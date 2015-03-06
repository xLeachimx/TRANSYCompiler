/*FILE: symtable.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of interface described in symtable.hpp
 *Notes:
*/

 #include "symtable.hpp"


SymTable::SymTable():Table(){
  nextAddr = 0;
}

int SymTable::insert(string symbol, int value){
  if(value+nextAddr >= MAX_TABLE_ENTRIES)return -1;
  int result = Table::insert(symbol,nextAddr);
  nextAddr = value+nextAddr;
  return result;
}


Core SymTable::genCore(){
	Core result = Core();
	for(int i = 0;i < insertLoc;i++){
		result.changeAddr(i,entries[i].value);
	}
	return result;
}