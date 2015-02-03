/*FILE: compiler.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implementation of the main compiler file
 */

#include "compiler.hpp"
#include "preprocess.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::remove;

//an enum used to assist commandType
enum{
  NOCOMMAND = -1,
  READ,
  WRITE,
  STOP,
  END,
};

//scans file for key words and generates object code from that scanning
string scan(string filename);
//determines the keyword categorization of a line
int commandType(string line);
//removes extension and appends .obj extension
string objName(string filename);

int main(int argc, char **argv){
  //flags
  bool keepNoSpace;
  keepNoSpace = false;
  char c;
  while(--argc > 0 && (*++argv)[0] == '-'){
    while(c = *++argv[0]){
      switch(c){
      case 'n':
	keepNoSpace = true;
	break;
      default:
	cout << "Bad flag:" << c <<endl;
	break;
      }
    }
  }
  vector<string> files;//holds the filenames for all the .nospaces files
  vector<string> objFiles;//holds the filenames for all the .obj files
  for(int i = 0;i < argc;i++){
    files.push_back(processFile(argv[i]));
  }
  for(int i = 0;i < files.size();i++){
    objFiles.push_back(scan(files[i]));
    if(!keepNoSpace)remove(files[i].c_str());
  }
  return 0;
}

string scan(string filename){
  ifstream fin;
  ofstream fout;
  string objFilename = objName(filename);
  fin.open(filename.c_str());
  fout.open(objFilename.c_str());
  if(!fin.is_open())return "ERROR";
  string line;
  getline(fin,line);
  while(!fin.eof()){
    switch(commandType(line)){
    case READ:
      fout << parseRead(line) <<endl;
      break;
    case WRITE:
      fout << parseWrite(line) <<endl;
      break;
    case STOP:
      fout << parseStop(line) <<endl;
      break;
    case END:
      fin.close();
      fout.close();
      return objFilename;
      break;
    default:
      cout << "Bad line" <<endl;
      break;
    }
    getline(fin,line);
  }
  fin.close();
  fout.close();
  return objFilename;
}

int commandType(string line){
  if(line.sub_str(0,4) == "READ")return READ;
  if(line.sub_str(0,5) == "WRITE")return WRITE;
  if(line.substr(0,4) == "STOP")return STOP;
  if(line.substr(0,3) == "END")return END;
  return NOCOMMAND;
}

string objName(string filename){
  string newName = filename;
  newName.erase(newName.rfind('.'));
  return newName+".obj";
}
