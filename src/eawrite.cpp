/*FILE: eawrite.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eawrite.hpp
 */

#include "eawrite.hpp"
#include "validity.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define AWRITE_OP_CODE 2

bool isAwrite(int opCode){
	return (AWRITE_OP_CODE==opCode);
}

int executeAwrite(int line[], int lineSize, Core *c){
	for(int i = line[1];i < line[2];i++){
		if(i%ITEMS_WRITTEN_BEFORE_NEWLINE == 0 && i != 0)cout << endl;
		cout << c->getAddrContent(line[0]+i);
	}
	return NO_ERROR;
}