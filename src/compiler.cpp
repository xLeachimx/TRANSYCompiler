/*FILE: compiler.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implementation of the main compiler file
 *Notes:
 *   Only recognizes commands READ, WRITE, STOP, END, CDUMP, CLS, NOP, LISTO, AREAD, AWRITE, DIM
 *   Error reporting limited to bad arguments and bad symbols
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
string scan(string filename, SymTable *symTable);
//determines the keyword categorization of a line
int commandType(string line);
//removes extension and appends .obj extension
string objName(string filename);
//grabs the extension of the filename
string extName(string filename);

int main(int argc, char **argv){
  //flags
  bool keepNoSpace;
  bool keepObj;
  bool skipPreproc;
  keepNoSpace = false;
  keepObj = false;
  skipPreproc = false;
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
  for(int i = 0;i < files.size();i++){
    //prep for first pass
    SymTable symTable = SymTable();
    objFile postScan = scan(files[i],&symTable);
    
    //should an error occur remove all obj and nospaces files
    if(postScan.valid){
       objFiles.push_back(postScan.name);
      if(!keepNoSpace)remove(files[i].c_str());
    }
    else{
      if(!keepObj)remove(postScan.name.c_str());
      if(!keepNoSpace)remove(files[i].c_str());
    }
  }
  return 0;
}


//implementation of scan function
objFile scan(string filename, SymTable *symTable){
  //setup the file io for the obj file
  ifstream fin;
  ofstream fout;
  string objFilename = objName(filename);
  fin.open(filename.c_str());
  fout.open(objFilename.c_str());
  
  if(!fin.is_open()){
    cout << "Could not open file:" << filename <<endl;
    return "";
  }
  
  string line;
  int lineNumber = 0;
  fin >> lineNumber;
  getline(fin,line);
  bool haltScan = false;//A flag to know when an error has occurred and therefore compilation should be stopped
  bool errorFound = false;
  while(!fin.eof()){
    int error = 0;
    
    line.erase(0,1);//removes the beginning space artifact left by the line tracking system
    
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
    case END:
      haltScan = true;
      break;
    default:
      cout << "No Known Command on line " << lineNumber <<endl;
      errorFound = true;
      break;
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
  return NOCOMMAND;
}

string objName(string filename){
  string newName = filename;
  newName.erase(newName.rfind('.'));
  return newName+".obj";
}

string extName(string filename){
  int extLoc = filename.rfind('.')+1;
  if(extLoc == 0)return "";
  return filename.substr(extLoc);
}
