/*FILE: compiler.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implementation of the main compiler file
 *Notes:
 *   Line labels are a little liberal.
 *   For example: label one == labelone
 */

#include "compiler.hpp"
#include "preprocess.hpp"
#include "validity.hpp"
#include "symtable.hpp"
#include "tread.hpp"
#include "twrite.hpp"
#include "tstop.hpp"
#include "tcdump.hpp"
#include "tcls.hpp"
#include "tnop.hpp"
#include "tlisto.hpp"
#include "taread.hpp"
#include "tawrite.hpp"
#include "tdim.hpp"
#include "core.hpp"
#include "table.hpp"
#include "tgoto.hpp"
#include "littable.hpp"
#include "tloopend.hpp"
#include "tlwrite.hpp"
#include "tlread.hpp"
#include "tifa.hpp"
#include "tif.hpp"
#include "tloop.hpp"
#include "tsubp.hpp"
#include "tassignment.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::remove;
using std::ifstream;
using std::ofstream;

//an enum used to assist commandType
enum CommandType{
  NOCOMMAND = -1,
  READ,
  WRITE,
  STOP,
  END,
  DIM,
  AREAD,
  AWRITE,
  CDUMP,
  NOP,
  LISTO,
  CLS,
  LREAD,
  LWRITE,
  LOOP,
  LOOPEND,
  IFA,
  IF,
  GOTO,
  SUBP,
};

//a small struct for use with determining validity of object code
struct objFile{
  string name;
  bool valid;
};

//scans file for key words and generates object code from that scanning
objFile scan(string filename, SymTable *symTable, Table *lineLabels);
//determines the keyword categorization of a line
int commandType(string line);
//removes extension and appends .obj extension
string objName(string filename);
//removes extension and appends .literal extension
string litName(string filename);
//removes extension and appends .core extension
string coreName(string filename);
//grabs the extension of the filename
string extName(string filename);
//scans file and removes line label
void populateLabelTable(string filename, Table *lineLabels);
//removes the line label from the str(if one is there)
string removeLineLabel(string str);

int main(int argc, char **argv){
  //flags
  bool keepNoSpace;
  bool keepObj;
  bool skipPreproc;
  bool globalSymTable;
  bool execute;
  keepNoSpace = false;
  keepObj = false;
  skipPreproc = false;
  globalSymTable = false;
  execute = false;
  char c;
  while(--argc > 0 && (*++argv)[0] == '-'){
    while((c = *++argv[0])){
      switch(c){
      case 'n':
        keepNoSpace = true;
        break;
      case 'o':
        keepObj = true;
        break;
      case 'p':
        skipPreproc = true;
        break;
      case 'g':
        globalSymTable = true;
        break;
      case 'x':
        execute = true;
        break;
      default:
        cout << "Bad flag:" << c <<endl;
        break;
      }
    }
  }
  vector<string> files;//holds the filenames for all the .noblanks files
  vector<string> objFiles;//holds the filenames for all the .obj files
  //preprocess the files
  for(int i = 0;i < argc;i++){
    if(!skipPreproc){
      string file = argv[i];
      if(extName(file) != ""){
        files.push_back(processFile(file));
      }
      else{
        files.push_back(processFile(file+".transy"));
      }
    }
    else{
      if(extName(argv[i]) != ""){
        files.push_back(argv[i]);
      }
      else{
        files.push_back(string(argv[i])+".noblanks");
      }
    }
  }
  if(argc == 0)files.push_back("test.transy");
  //turn preproecessed files into obj in first pass
  SymTable symTable = SymTable();
  for(int i = 0;i < files.size();i++){
    //prep for first pass
    if(!globalSymTable)symTable = SymTable();
    Table lineLabel = Table();
    populateLabelTable(files[i],&lineLabel);
    objFile postScan = scan(files[i],&symTable,&lineLabel);
    
    //should an error occur remove all obj and nospaces files
    if(postScan.valid){
       objFiles.push_back(postScan.name);
      if(!keepNoSpace)remove(files[i].c_str());
      if(execute){
        // executorMain(2,{"",objFiles[objFiles.last()].c_str()});
      }
    }
    else{
      if(!keepObj)remove(postScan.name.c_str());
      if(!keepNoSpace)remove(files[i].c_str());
    }
  }
  return 0;
}


//implementation of scan function
objFile scan(string filename, SymTable *symTable, Table *lineLabels){
  //setup the file io for the obj file
  ifstream fin;
  ofstream fout;
  string objFilename = objName(filename);
  fin.open(filename.c_str());
  fout.open(objFilename.c_str());
  
  if(!fin.is_open()){
    cout << "Could not open file:" << filename <<endl;
    objFile blank;
    blank.valid = false;
    return blank;
  }
  
  //setup some literals
  LitTable literals = LitTable();

	string line;
	int lineNumber = 0;
	fin >> lineNumber;
	getline(fin,line);
	bool haltScan = false;//A flag to know when an error has occurred and therefore compilation should be stopped
	bool errorFound = false;
	while(!fin.eof()){
		int error = 0;
		
		line.erase(0,1);//removes the beginning space artifact left by the line tracking system
    line = removeLineLabel(line);
    int assignmentError = 0;
    if(assignmentError = validAssignment(line, symTable)) == 0){
      fout << parseAssignment(line, symTable) <<endl;
    }
    else{
      switch(commandType(line)){
      case READ:
        if((error=validRead(line)) == 0){
          fout << parseRead(line, symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << " on READ command" <<endl;
          errorFound = true;
        }
        break;
      case WRITE:
        if((error=validWrite(line)) == 0){
          fout << parseWrite(line, symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << " on WRITE command" <<endl;
          errorFound = true;
        }
        break;
      case STOP:
        if((error=validStop(line)) == 0){
          fout << parseStop(line) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << " on STOP command" <<endl;
          errorFound = true;
        }
        break;
      case DIM:
        if((error=validDim(line,symTable)) == 0){
          parseDim(line,symTable);
          //only do this if need be dim op code is exported
          //fout << parseStop(line) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << " on DIM command" <<endl;
          errorFound = true;
        }
        break;
      case CDUMP:
        if((error=validCdump(line)) == 0){
          fout << parseCdump(line) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on CDUMP command" <<endl;
          errorFound = true;
        }
        break;
      case LISTO:
        if((error=validListo(line)) == 0){
          fout << parseListo(line) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on NOP command" <<endl;
          errorFound = true;
        }
        break;
      case NOP:
        if((error=validNop(line)) == 0){
          fout << parseNop(line) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on NOP command" <<endl;
          errorFound = true;
        }
        break;
      case AREAD:
        if((error=validAread(line, symTable)) == 0){
          fout << parseAread(line, symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on AREAD command" <<endl;\
          errorFound = true;
        }
        break;
      case AWRITE:
        if((error=validAwrite(line, symTable)) == 0){
          fout << parseAwrite(line, symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on AWRITE command" <<endl;
          errorFound = true;
        }
        break;
      case CLS:
        if((error=validCls(line)) == 0){
          fout << parseCls(line) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on CLS command" <<endl;
          errorFound = true;
        }
        break;
      case GOTO:
        if((error=validGoto(line,lineLabels)) == 0){
          fout << parseGoto(line,lineLabels) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on GOTO command" <<endl;
          errorFound = true;
        }
        break;
      case LREAD:
        if((error=validLread(line,&literals)) == 0){
          fout << parseLread(line,&literals) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on LREAD command" <<endl;
          errorFound = true;
        }
        break;
      case LOOPEND:
        if((error=validLoopend(line)) == 0){
          fout << parseLoopend(line) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on LOOP-END command" <<endl;
          errorFound = true;
        }
        break;
      case LWRITE:
        if((error=validLwrite(line,&literals)) == 0){
          fout << parseLwrite(line,&literals) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on LWRITE command" <<endl;
          errorFound = true;
        }
        break;
      case IFA:
        if((error=validIfa(line,lineLabels,symTable)) == 0){
          fout << parseIfa(line,lineLabels,symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on IFA command" <<endl;
          errorFound = true;
        }
        break;
        case IF:
        if((error=validIf(line,lineLabels,symTable)) == 0){
          fout << parseIf(line,lineLabels,symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on IF command" <<endl;
          errorFound = true;
        }
        break;
        case LOOP:
        if((error=validLoop(line,symTable)) == 0){
          fout << parseLoop(line,symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on LOOP command" <<endl;
          errorFound = true;
        }
        break;
        case SUBP:
        if((error=validSubp(line,symTable)) == 0){
          fout << parseSubp(line,symTable) <<endl;
        }
        else{
          cout << "Error on line " << lineNumber << ": " << errorString(error) << "on SUBP command" <<endl;
          errorFound = true;
        }
        break;
      case END:
        haltScan = true;
        break;
      default:
        if(assignmentError != 0){
          cout << "Error on line " << lineNumber << ": " << errorString(assignmentError) <<endl;
          errorFound = true;
        }
        break;
      }
    }
      if(haltScan)break;
      fin >> lineNumber;
      getline(fin,line);
  }
  fin.close();
  fout.close();
  objFile result;
  result.name = objFilename;
  result.valid = !errorFound;
  symTable->genCore(result.valid).toFile(coreName(filename));
  literals.toFile(litName(filename));
  return result;
}

int commandType(string line){
  if(line.substr(0,4) == "READ")return READ;
  if(line.substr(0,5) == "WRITE")return WRITE;
  if(line.substr(0,4) == "STOP")return STOP;
  if(line.substr(0,3) == "END")return END;
  if(line.substr(0,3) == "DIM")return DIM;
  if(line.substr(0,5) == "CDUMP")return CDUMP;
  if(line.substr(0,5) == "LISTO")return LISTO;
  if(line.substr(0,3) == "NOP")return NOP;
  if(line.substr(0,5) == "AREAD")return AREAD;
  if(line.substr(0,6) == "AWRITE")return AWRITE;
  if(line.substr(0,3) == "CLS")return CLS;
  if(line.substr(0,4) == "GOTO")return GOTO;
  if(line.substr(0,5) == "LREAD")return LREAD;
  if(line.substr(0,8) == "LOOP-END")return LOOPEND;
  if(line.substr(0,6) == "LWRITE")return LWRITE;
  if(line.substr(0,3) == "IFA")return IFA;
  if(line.substr(0,2) == "IF")return IF;
  if(line.substr(0,4) == "LOOP")return LOOP;
  if(line.substr(0,4) == "SUBP")return SUBP;
  
  return NOCOMMAND;
}

string objName(string filename){
  string newName = filename;
  newName.erase(newName.rfind('.'));
  return newName+".obj";
}

string litName(string filename){
  string newName = filename;
  newName.erase(newName.rfind('.'));
  return newName+".literal";
}

string coreName(string filename){
  string newName = filename;
  newName.erase(newName.rfind('.'));
  return newName+".core";
}

string extName(string filename){
  int extLoc = filename.rfind('.')+1;
  if(extLoc == 0)return "";
  return filename.substr(extLoc);
}

void populateLabelTable(string filename, Table *lineLabels){
  ifstream fin;
  fin.open(filename.c_str());
  
  if(!fin.is_open()){
    cout << "Could not open file:" << filename <<endl;
    return;
  }

  int temp = 0;
  fin >> temp;//remove line relation
  string line = "";
  getline(fin,line);
  line.erase(0,1);//remove artifact space

  int lineCount = 0;

	while(!fin.eof()){
		int colonLoc = line.find(':'); //internal to human body
		string label = line.substr(0,colonLoc);
		if(colonLoc != -1){
			lineLabels->insert(label,lineCount);
		}
    temp = 0;
    fin >> temp;//remove line relation
    line = "";
    getline(fin,line);
    line.erase(0,1);//remove artifact space
    lineCount++;
  }
  fin.close();
}

string removeLineLabel(string str){
  int colonLoc = str.find(':'); //internal to human body
  string label = str.substr(0,colonLoc);
  if(colonLoc == -1){
    return str;
  }
  str.erase(0,colonLoc+1);
  return str;
}
