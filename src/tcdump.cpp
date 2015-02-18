/*FILE:tcdump.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tstop.hpp
 *Notes:
*/

#include "tcdump.hpp"
#include "validity.hpp"

//implementation of parseRead func
string parseCdump(string line){
  string obj = "5 ";
  line.erase(0,5);//get rid of CDUMP
  vector<string> args = split(line,',');
  obj += args[0] + ' ';
  obj += args[1];
  return obj;
}


//implementation of validStop function
int validCdump(string line){
  line.erase(0,5);//get rid of CDUMP
  vector<string> args = split(line,',');
  if(args.size() != 2)return BAD_ARGS;
  if(validNumber(args[0]))return BAD_ARGS;
  if(validNumber(args[1]))return BAD_ARGS;
  return NO_ERROR;
}
