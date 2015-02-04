/*FILE: symtable.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of interface described in symtable.hpp
 *Notes:
*/

 #include "symtable.hpp"

#define COREMEMSIZE 1000 //define the size of core memory

SymTable::SymTable():Table(COREMEMSIZE){
  nextAddr = 0;
}

int SymTable::insert(string symbol, int value){
  if(value+nextAddr >= COREMEMSIZE)return -1;
  int result = Table::insert(symbol,nextAddr);
  nextAddr = value+nextAddr;
  return result;
}
