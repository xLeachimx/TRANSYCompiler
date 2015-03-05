/*FILE:tdim.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tdim.hpp
 *Notes:
*/

#include "tdim.hpp"
#include "validity.hpp"

//using std::to_string;
#include <cstdio>
#include <cstdlib>
using std::sprintf;
using std::atoi;

//implementation of parseDim func
string parseDim(string line, SymTable *symTable){
  line.erase(0,3);//get rid of DIM
  vector<string> arys = split(line,',');
  //string result = "0 ";
  for(int i = 0;i < arys.size();i++){
    int leftBrac = arys[i].find('[');
    int rightBrac = arys[i].rfind(']');
    string symbol = arys[i].substr(0,leftBrac);
    int numberSize = rightBrac - (leftBrac+1);
    string number = arys[i].substr(leftBrac+1,numberSize);
    symTable->insert(symbol,atoi(number.c_str()));
    //char buffer[10];
    //sprintf(buffer,"%d",addr);
    //result += buffer;
    //if(i < symbols.size()-1)result += " ";
  }
  //return result;
  return "";
}


//implementation of validDim function
int validDim(string line, SymTable *symTable){
  line.erase(0,3);//get rid of DIM
  vector<string> arys = split(line,',');
  vector<string> decArys = vector<string>();
  if(numberOf(line,',') != arys.size()-1 || arys.size() <= 0)return BAD_ARGS;
  for(int i = 0;i < arys.size();i++){
    int leftBrac = arys[i].find('[');
    int rightBrac = arys[i].rfind(']');
    string symbol = arys[i].substr(0,leftBrac);
    int numberSize = rightBrac - (leftBrac+1);
    string number = arys[i].substr(leftBrac+1,numberSize);
    if(!validSymbol(symbol))return INVALID_SYMBOLS;
    if(!validNumber(number))return INVALID_NUMBER;
    for(int j = 0;j < decArys.size();j++){
      if(symbol == decArys[j])return DUPLICATE_DECLARATION;
    }
    if(symTable->retrieve(symbol) != -1)return DUPLICATE_DECLARATION;
  }
  return NO_ERROR;
}
