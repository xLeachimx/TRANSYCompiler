/*FILE:tloopend.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tloopend.hpp
 *Notes:
*/

#include "tloopend.hpp"
#include "validity.hpp"

//implementation of parseLoopend func
string parseLoopend(string line){
  return "15";
}


//implementation of validLoopend function
int validLoopend(string line){
  line.erase(0,8);//get rid of LOOP-END
  if(line.length() > 0)return EXCESS_CHARS;
  return NO_ERROR;
}
