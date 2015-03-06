/*FILE: littable.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of interface described in littable.hpp
 *Notes:
*/

 #include "littable.hpp"
 #include <fstream>
 using std::endl;
 using std::ofstream;


LitTable::LitTable():Table(){
  nextAddr = 0;
}

int LitTable::insert(string symbol){
  if(nextAddr >= MAX_TABLE_ENTRIES)return -1;
  int result = Table::insert(symbol,nextAddr);
  nextAddr++;
  return result;
}

void LitTable::toFile(string filename){
	if(insertLoc == 0)return;
	ofstream fout;
	fout.open(filename.c_str());
	for(int i = 0;i < insertLoc;i++){
		if(entries[i].symbol[0] == '$'){
			fout << "" <<endl;//handle variables
		}
		else{
			fout << entries[i].symbol <<endl;
		}
	}
	fout.close();
}