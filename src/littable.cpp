/*FILE: littable.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of interface described in littable.hpp
 *Notes:
*/

 #include "littable.hpp"


LitTable::LitTable():Table(){
  nextAddr = 0;
}

int LitTable::insert(string symbol){
  if(value >= MAX_TABLE_ENTRIES)return -1;
  int result = Table::insert(symbol,nextAddr);
  nextAddr++;
  return result;
}
