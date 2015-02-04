/*FILE:tstop.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tstop.hpp
 *Notes:
*/

#include "tstop.hpp"
#include "validity.hpp"

//implementation of parseRead func
string parseStop(string line){
  return "2";
}


//implementation of validStop function
int validStop(string line){
  line.erase(0,4);//get rid of STOP
  if(line.length() > 0)return EXCESS_CHARS;
  return NO_ERROR;
}
