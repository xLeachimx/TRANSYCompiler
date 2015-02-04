/*FILE:twrite.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in twrite.hpp
 *Notes:
*/

#include "twrite.hpp"
#include "validity.hpp"

//implementation of parseWrite func
string parseWrite(string line, SymTable &symTable){
  line.erase(0,5);//get rid of WRITE
  vector<string> symbols = split(line,',');
  string result = "2 ";
  for(int i = 0;i < symbols.size();i++){
    result += numToStr(symTable.retrieve(symbols[i]));
    if(i != symbols.size()-1)result += " ";
  }
  return result;
}


//implementation of validWrite function
int validWrite(string line, SymTable &symTable){
  line.erase(0,4);//get rid of READ
  vector<string> symbols = split(line,',');
  if(numberOf(line,',') != symbols.size()-1){
    return BAD_ARGS;
  }
  for(int i = 0;i < symbols.size();i++){
    if(symTable.retrieve(symbols[i]) == -1)return BAD_SYMBOLS;
    if(!validSymbol(symbols[i]))return INVALID_SYMBOLS;
  }
  return NONE;
}
