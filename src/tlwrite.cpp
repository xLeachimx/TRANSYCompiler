/*FILE:tlwrite.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of tlwrite.hpp
 *Notes:
*/

#include "tlwrite.hpp"
#include "validity.hpp"

#include <cstdio>
using std::sprintf;

#include <iostream>
using std::cout;
using std::endl;


//implementation of parseLwrite function
string parseLwrite(string line, LitTable *litTable){
  line.erase(0,6);//get rid of LWRITE
  string result = "17 ";
  int litLoc = -1;
  cout << line <<endl;
  if(line[0] == '\"'){
    line.erase(0,1);
    line.erase(line.rfind('\"'),1);
    litLoc = litTable->retrieve(line);
    cout << line <<endl;
  }
  else{
    litLoc = litTable->retrieve(line);
  }
  char buffer[10];
  sprintf(buffer,"%d",litLoc);
  result += buffer;
  return result;
}

//implementation of validLwrite function
int validLwrite(string line, LitTable *litTable){
  line.erase(0,6);//get rid of LWRITE
  if(line[0] == '$'){
    if(!validLiteralSymbol(line))return INVALID_SYMBOLS;
    return NO_ERROR;
  }
  else if(line[0] == '\"'){
    line.erase(0,1);//remove the first '
    int endLoc = line.find('\"');
    if(endLoc == -1)return BAD_LITERAL;
    string lit = line.substr(0,endLoc);
    line.erase(0,endLoc+1);
    if(line.length() != 0)return BAD_LITERAL;
    if(litTable->retrieve(lit) == -1)litTable->insert(lit);
    return NO_ERROR;
  }
  return BAD_ARGS;
}
