/*FILE: preprocess.cpp
*Author: Michael Huelsman
*Description:
*	Implements the function processFile from the file preprocessor.hpp
*/
#include "preprocess.hpp"
#include "validity.hpp"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
using std::getline;

string removal(string filename);//handles all the removal and capitalization tasks
string newFilename(string filename);
char capitalize(char c);
bool isWhiteSpace(char c);

string processFile(string filename){
  return removal(filename);
}

string removal(string filename){
  ifstream origin;
  ofstream nospace;

  origin.open(filename.c_str());
  nospace.open(newFilename(filename).c_str());

  if(!origin.is_open())return "";
  if(!nospace.is_open())return "";

  string line;

  int lineCount = 1;

  do{
    getline(origin, line);
    if(origin.eof())break;
    bool inQuote = false;
    for(int i = 0;i < line.length();i++){
      if(line[i] == '\"')inQuote = !inQuote;//detect quotes
      if(inQuote)continue;
      //remove whitespace
      if(isWhiteSpace(line[i])){
        line.erase(i,1);
        i--;
        continue;
      }
      line[i] = capitalize(line[i]);
      //check for comments
      if(line[i] == 'C'){
        if(i+1 < line.length()){
          if(line[i+1] == '*'){
            //remove comments
            line.erase(i);
            i--;
          }
        }
      }
    }
    if(line.length() > 0){
      nospace << lineCount << " ";
      nospace << line <<endl;
    }
    lineCount++;
  }while(!origin.eof());

  return newFilename(filename);
}

string newFilename(string filename){
  string name = filename.erase(filename.rfind(".")); // strip the filename of the extension
  name += ".noblanks";
  return name;
}

char capitalize(char c){
  // find lower case letters and adjust the ascii values to upper case
  if(c >= 97 && c <= 122){;
    c -= 32;
  }
  return c;
}

bool isWhiteSpace(char c){
  return (c == ' ' || c == '\t');
}