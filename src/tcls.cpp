/*FILE:tcls.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tcls.hpp
 *Notes:
*/

#include "tcls.hpp"
#include "validity.hpp"

//implementation of parseRead func
string parseCls(string line){
  return "19";
}


//implementation of validStop function
int validCls(string line){
  line.erase(0,3);//get rid of CLS
  if(line.length() > 0)return EXCESS_CHARS;
  return NO_ERROR;
}
