/*FILE:taread.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in taread.hpp
 *Notes:
*/

#include "taread.hpp"
#include "validity.hpp"

//using std::to_string;
#include <cstdio>
#include <cstdlib>
using std::sprintf;

//implementation of parseAread func
string parseAread(string line, SymTable *symTable){
  line.erase(0,5);//get rid of AREAD
  vector<string> args = split(line,',');
  string result = "11 ";
  for(int i = 0;i < args.size();i++){
    int addr = -1;
    char buffer[10];
    if(validNumber(args[i]))args[i] = standardizeNumber(args[i]);
    sprintf(buffer,"%d",symTable->retrieve(args[i]));
    result += buffer;
    result += ' ';
  }
  return result;
}


//implementation of validAread function
int validAread(string line, SymTable *symTable){
  line.erase(0,5);//get rid of AREAD
  vector<string> args = split(line,',');
  if(numberOf(line,',') != 2 || args.size() != 3){
    return BAD_ARGS;
  }
  if(!validSymbol(args[0]))return INVALID_SYMBOLS;
  if(!validNumber(args[1]) && !validSymbol(args[1]))return BAD_ARGS;
  if(!validNumber(args[2]) && !validSymbol(args[2]))return BAD_ARGS;
  if(symTable->retrieve(args[0]) == -1)return UNDECLARED_ARRAY;
  if(symTable->retrieve(args[1]) == -1){
    if(!validNumber(args[1]))return INVALID_SYMBOLS;
    if(validNumber(args[1])){
      args[1] = standardizeNumber(args[1]);
      if(symTable->retrieve(args[1]) == -1)symTable->insert(args[1],1);
    }
  }
  if(symTable->retrieve(args[2]) == -1){
    if(!validNumber(args[2]))return INVALID_SYMBOLS;
    if(validNumber(args[2])){
      args[2] = standardizeNumber(args[2]);
      if(symTable->retrieve(args[2]) == -1)symTable->insert(args[2],1);
    }
  }
  return NO_ERROR;
}
