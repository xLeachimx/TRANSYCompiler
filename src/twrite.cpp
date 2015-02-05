/*FILE:twrite.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in twrite.hpp
 *Notes:
*/

#include "twrite.hpp"
#include "validity.hpp"
#include <cstdio>

using std::sprintf;
//using std::to_string;

#include <iostream>
using std::cout;
using std::endl;

//implementation of parseWrite func
string parseWrite(string line, SymTable *symTable){
  line.erase(0,5);//get rid of WRITE
  vector<string> symbols = split(line,',');
  string result = "2 ";
  for(int i = 0;i < symbols.size();i++){
    int addr = -1;
    //what to do if the symbol is not in the table
    if((addr = symTable->retrieve(symbols[i])) == -1){
      addr = symTable->insert(symbols[i],1);
    }
    char buffer[10];
    sprintf(buffer,"%d",addr);
    result += buffer;
    if(i != symbols.size()-1)result += " ";
  }
  return result;
}


//implementation of validWrite function
int validWrite(string line){
  line.erase(0,5);//get rid of WRITE
  vector<string> symbols = split(line,',');
  if(numberOf(line,',') != symbols.size()-1 || symbols.size() <= 0){
    return BAD_ARGS;
  }
  for(int i = 0;i < symbols.size();i++){
    if(!validSymbol(symbols[i]))return INVALID_SYMBOLS;
  }
  return NO_ERROR;
}
