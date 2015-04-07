/*FILE: earead.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in earead.hpp
 */

#include "earead.hpp"
#include "validity.hpp"

#include <iostream>
using std::cin;

#define AREAD_OP_CODE 11

bool isAread(int opCode){
	return (AREAD_OP_CODE==opCode);
}

int executeAread(int line[], int lineSize, Core *c){
	for(int i = line[1];i < line[2];i++){
		double temp = 0.0;
		cin >> temp;
		c->changeAddr(line[0]+i,temp);
	}
	return NO_ERROR;
}