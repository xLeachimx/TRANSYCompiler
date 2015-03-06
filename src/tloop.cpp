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
using std::sprintf;
using std::atoi;

//implementation of parseLoop func
string parseLoop(string line, SymTable *symTable){
  line.erase(0,4);//get rid of LOOP
  vector<string> args = split(line,',');
  string result = "14 ";
  //detect intialization
  int eqlLoc = args[0].find('=');
  string symbol = args[0].substr(0,eqlLoc);
  args[0].erase(0,eqlLoc+1);
  symLoc = -1;
  if((symLoc=symTable->retrieve(symbol)) == -1){
    symLoc = symTable->insert(symbol,1);
  }
  char buffer[10];
  sprintf(buffer,"%d",symLoc); 
  result += buffer;
  result += ' ';

  symLoc = symTable->retrieve(args[0]);
  sprintf(buffer,"%d",symLoc);
  result += buffer;
  result += ' ';

  symLoc = symTable->retrieve(args[1]);
  sprintf(buffer,"%d",symLoc);
  result += buffer;
  result += ' ';

  symLoc = symTable->retrieve(args[2]);
  sprintf(buffer,"%d",symLoc);
  result += buffer;
  return result;
}


//implementation of validAread function
int validAread(string line, SymTable *symTable){
  line.erase(0,4);//get rid of LOOP
  vector<string> args = split(line,',');
  if(numberOf(line,',') != 2)return BAD_ARGS;
  if(numberOf(line,'='))return BAD_ARGS;
  if(args.size() != 3)return BAD_ARGS;

  //detect intialization
  int eqlLoc = args[0].find('=');
  string symbol = args[0].substr(0,eqlLoc);
  args[0].erase(0,eqlLoc+1);
  symLoc = -1;
  if(!validSymbol(symbol))return INVALID_SYMBOLS;

  for(int i = 0;i < 3;i++){
    if(validSymbol(args[i])){
      if(symTable->retrieve(args[i]) == -1)return BAD_ARGS;
    }
    else{
      if(!validNumber(args[i]))return BAD_ARGS;
      if(symTable->retrieve(args[i]) == -1){
        symTable->insert(standarizeNumber(args[i]),1);
      }
    }
  }
  return NO_ERROR;
}
