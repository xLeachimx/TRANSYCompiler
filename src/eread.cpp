/*FILE: eread.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eread.hpp
 */

#include "eread.hpp"
#include "validity.hpp"

#include <iostream>
using std::cin;

#define READ_OP_CODE 1

bool isRead(int opCode){
	return (READ_OP_CODE==opCode);
}

int executeRead(int line[], int lineSize, Core *c){
	for(int i = 0;i < lineSize;i++){
		double temp = 0.0;
		cin >> temp;
		c->changeAddr(line[i],temp);
	}
	return NO_ERROR;
}