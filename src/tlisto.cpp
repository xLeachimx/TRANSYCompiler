/*FILE:tlisto.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of the interface outlined in tlisto.hpp
 *Notes:
*/

#include "tlisto.hpp"
#include "validity.hpp"

//implementation of parseListo func
string parseListo(string line){
  return "6";
}


//implementation of validStop function
int validListo(string line){
  line.erase(0,5);//get rid of LISTO
  if(line.length() > 0)return EXCESS_CHARS;
  return NO_ERROR;
}
