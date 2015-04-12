/*FILE: ecdump.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in edump.hpp
 */

#include "ecdump.hpp"
#include "validity.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define CDUMP_OP_CODE 5

bool isCdump(int opCode){
	return (CDUMP_OP_CODE==opCode);
}

int executeCdump(int line[], int lineSize, Core *c){
	if(line[0] < 0 || line[0] >= CORE_SIZE)return SEG_FAULT;
	if(line[1] < 0 || line[1] >= CORE_SIZE)return SEG_FAULT;
	if(line[0] > line[1])return INVALID_RANGE;
	cout << "=====BEGIN CDUMP======" <<endl;
	for(int i = line[0];i <= line[1];i++){
		if(i%ITEMS_WRITTEN_BEFORE_NEWLINE == 0 && i != 0)cout << endl;
		cout << c->getAddrContent(i) << "\t";
	}
	cout << endl << "=====END CDUMP======" <<endl;
	return NO_ERROR;
}