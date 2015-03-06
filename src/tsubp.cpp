/*FILE:tsubp.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tsubp.hpp
 *Notes:
*/

#include "tsubp.hpp"
#include "validity.hpp"

//using std::to_string;
#include <cstdio>
#include <cstdlib>
using std::sprintf;
using std::atoi;

//implementation of parseSubp func
string parseSubp(string line, SymTable *symTable){
  line.erase(0,4);//get rid of Subp
  string result = "13 "
  int leftBrac = line.find('(');
  int rightBrac = line.rfind(')');
  string func = line.substr(0,leftBrac);
  line.erase(0,leftBrac+1);
  string parse = line.substr(0,rightBrac);

  if(func == "SIN"){
    result += "0 "
  }
  else if(func == "COS"){
    result += "1 "
  }
  else if(func == "EXP"){
    result += "2 "
  }
  else if(func == "ABS"){
    result += "3 "
  }
  else if(func == "ALG"){
    result += "4 "
  }
  else if(func == "SQR"){
    result += "5 "
  }

  vector<string> args = split(parse,',');

  int symLoc = symTable->retrieve(args[0]);
  char buffer[10];
  sprintf(buffer,"%d",symLoc);
  result += buffer;
  result += ' ';

  symLoc = symTable->retrieve(args[1]);
  if(symLoc == -1){
    symLoc == symTable->insert(args[1],1)
  }
  sprintf(buffer,"%d",symLoc);
  result += buffer;

  return result;
}


//implementation of validSubp function
int validSubp(string line, SymTable *symTable){
  line.erase(0,4);//get rid of Subp
  int leftBrac = line.find('(');
  int rightBrac = line.rfind(')');
  if(leftBrac == -1 || rightBrac == -1)return BAD_ARGS;
  string func = line.substr(0,leftBrac);
  line.erase(0,leftBrac+1);
  string parse = line.substr(0,rightBrac);

  if(func != "SIN" && func != "COS" && func != "EXP" && func != "ABS" && func != "ALG" && func != "SQR"){
    return BAD_ARGS;
  }

  vector<string> args = split(parse,',');
  if(args.size() != 2)return BAD_ARGS;

  if(validSymbol(args[0])){
    int symLoc = symTable->retrieve(args[0]);
    if(symLoc == -1)return BAD_ARGS;
  }
  else if(validNumber(args[0])){
    int symLoc = symTable->retrieve(args[0]);
    if(symLoc == -1)symTable->insert(args[0]);
  }
  else{
    return INVALID_SYMBOLS;
  }

  if(!validSymbol(args[1])){
    if(validNumber(args[0])){
      int symLoc = symTable->retrieve(args[0]);
      if(symLoc == -1)symTable->insert(args[0]);
    }
    else{
      return BAD_ARGS;
    }
  }
  return NO_ERROR;
}
