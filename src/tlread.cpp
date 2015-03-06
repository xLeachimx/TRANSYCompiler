/*FILE:tlread.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of tlread.hpp
 *Notes:
*/

#include "tlread.hpp"
#include "validity.hpp"

#include <cstdio>
using std::sprintf;

//implementation of parseLread function
string parseLread(string line, LitTable *litTable){
  line.erase(0,5);//get rid of LREAD
  string result = "17 ";
  int litLoc = litTable->retrieve(line);
  if(litLoc == -1){
    litLoc = litTable->insert(line);
  }
  char buffer[10];
  sprintf(buffer,"%d",litLoc);
  result += buffer;
  return result;
}

//implementation of validLread function
int validLread(string line, LitTable *litTable){
  line.erase(0,5);//get rid of LREAD
  if(!validLiteralSymbol(line))return INVALID_SYMBOLS;
  return NO_ERROR;
}
