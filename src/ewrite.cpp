/*FILE: ewrite.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in ewrite.hpp
 */

#include "ewrite.hpp"
#include "validity.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define WRITE_OP_CODE 2

bool isWrite(int opCode){
	return (WRITE_OP_CODE==opCode);
}

int executeWrite(int line[], int lineSize, Core *c){
	for(int i = 0;i < lineSize;i++){
		if(i%ITEMS_WRITTEN_BEFORE_NEWLINE == 0 && i != 0)cout << endl;
		cout << c->getAddrContent(line[i]);
	}
	return NO_ERROR;
}