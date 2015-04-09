/*FILE:tloop.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tloop.hpp
 *Notes:
*/

#include "tloop.hpp"
#include "validity.hpp"

//using std::to_string;
#include <cstdio>
#include <cstdlib>
using std::printf;
using std::sprintf;

//implementation of parseLoop func
string parseLoop(string line, SymTable *symTable){
  line.erase(0,4);//get rid of LOOP
  vector<string> args = split(line,',');
  string result = "14 ";
  //detect intialization
  int eqlLoc = args[0].find('=');
  string symbol = args[0].substr(0,eqlLoc);
  args[0].erase(0,eqlLoc+1);
  int symLoc = -1;
  if((symLoc=symTable->retrieve(symbol)) == -1){
    symLoc = symTable->insert(symbol,1);
  }
  char buffer[10];
  sprintf(buffer,"%d",symLoc); 
  result += buffer;

  for(int i = 0;i < 3;i++){
    result += ' ';
    if(validNumber(args[i]))args[i] = standardizeNumber(args[i]);
    symLoc = symTable->retrieve(args[i]);
    sprintf(buffer,"%d",symLoc);
    result += buffer;
  }
  return result;
}


//implementation of validLoop function
int validLoop(string line, SymTable *symTable){
  line.erase(0,4);//get rid of LOOP
  vector<string> args = split(line,',');
  if(numberOf(line,',') != 2)return BAD_ARGS;
  if(numberOf(line,'=') != 1)return BAD_ARGS;
  if(args.size() != 3)return BAD_ARGS;

  //detect intialization
  int eqlLoc = args[0].find('=');
  string symbol = args[0].substr(0,eqlLoc);
  args[0].erase(0,eqlLoc+1);
  int symLoc = -1;
  if(!validSymbol(symbol))return INVALID_SYMBOLS;

  for(int i = 0;i < 3;i++){
    if(validSymbol(args[i]) || validNumber(args[i])){
      if(validNumber(args[i]))args[i] = standardizeNumber(args[i]);
      if(symTable->retrieve(args[i]) == -1){
        symTable->insert(args[i],1);
      }
    }
    else{
      return INVALID_SYMBOLS;
    }
  }
  return NO_ERROR;
}
