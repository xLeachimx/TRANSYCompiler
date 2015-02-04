/*FILE:tread.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tread.hpp
 *Notes:
*/

#include "tread.hpp"
#include "validity.hpp"

//implementation of parseRead func
string parseRead(string line, SymTable &symTable){
  line.erase(0,4);//get rid of READ
  vector<string> symbols = split(line,',');
  string result = "1 ";
  for(int i = 0;i < symbols.size();i++){
    int addr = -1;
    //what to do if the symbol is not in the table
    if(symTable.retrieve(symbols[i]) == -1){
      addr = symTable.insert(symbols[i],1);
    }
    result += numToStr(addr);
    if(i != symbols.size()-1)result += " ";
  }
  return result;
}


//implementation of validRead function
int validRead(string line){
  line.erase(0,4);//get rid of READ
  vector<string> symbols = split(line,',');
  if(numberOf(line,',') != symbols.size()-1){
    return BAD_ARGS;
  }
  for(int i = 0;i < symbols.size();i++){
    if(!validSymbol(symbols[i]))return INVALID_SYMBOLS;
  }
  return NO_ERROR;
}
