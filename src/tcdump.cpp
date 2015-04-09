/*FILE:tcdump.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tstop.hpp
 *Notes:
*/

#include "tcdump.hpp"
#include "validity.hpp"
#include <cstdlib>
using std::atoi;

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
  if(numberOf(line,',') != 1 || args.size() != 2)return BAD_ARGS;
  if(!validNumber(args[0]))return BAD_ARGS;
  if(args[0][0] == '-')return BAD_NUMBER;
  if(!validNumber(args[1]))return BAD_ARGS;
  if(args[1][0] == '-')return BAD_ARGS;
  if(atoi(args[0].c_str()) > atoi(args[1].c_str()))return BAD_ARGS;
  return NO_ERROR;
}
