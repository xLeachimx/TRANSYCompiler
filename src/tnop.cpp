/*FILE:tnop.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tnop.hpp
 *Notes:
*/

#include "tnop.hpp"
#include "validity.hpp"

//implementation of parseRead func
string parseNop(string line){
  return "7";
}


//implementation of validStop function
int validNop(string line){
  line.erase(0,3);//get rid of NOP
  if(line.length() > 0)return EXCESS_CHARS;
  return NO_ERROR;
}
