/*FILE:core.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of interface in core.hpp
 *
 */
//implementation of core constructor

#include "core.hpp"
#include <fstream>
using std::endl;
using std::ofstream;

Core::Core(){
  for(int i = 0;i <= MAX_CORE_LOC;i++){
    data[i] = DEFAULT_VAL;
  }
  data[VALID_FLAG_LOC] = COMP_FAIL
}

//implementation of the changeAddr
bool Core::changeAddr(int addr, double to){
  if(addr <= MAX_CORE_LOC || addr < 0){
    return false;
  }
  data[addr] = to;
  return true;
}

//implementation of the getAddrContent 
double Core::getAddrContent(int addr){
  if(addr <= MAX_CORE_LOC || addr < 0){
    return DEFAULT_VAL;
  }
  return data[addr];
}

void toFile(string filename){
  ofstream fout;
  fout.open(filename.c_str());
  for(int i = 0;i < MAX_CORE_LOC;i++){
    fout << data[i] <<endl;
  }
  fout.close();
}