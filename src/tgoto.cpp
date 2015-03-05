/*FILE:tgoto.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of tgoto.hpp
 *Notes:
*/

#include "tgoto.hpp"
#include "validity.hpp"

#include <cstdio>
using std::sprintf;

//implementation of parseGoto function
string parseGoto(string line, Table *lineTable){
  line.erase(0,4);//get rid of GOTO
  result = "8 "
  lineReferred = lineTable->retreive(line);
  char buffer[10];
  sprintf(buffer,"%d",lineReferred);
  result += buffer;
  return result;
}

//implementation of validGoto function
int validGoto(string line, Table *lineTable){
  line.erase(0,4);//get rid of GOTO
  if(!validSymbol(line))return INVALID_SYMBOLS;
  lineReferred = lineTable->retrieve(line);
  if(lineReferred == -1)return BAD_LINE_LABEL;
  return NO_ERROR;
}
