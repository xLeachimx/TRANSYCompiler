/*FILE: eifa.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eifa.hpp
 */

#include "eifa.hpp"
#include "validity.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define IFA_OP_CODE 10

bool isIfa(int opCode){
	return (IFA_OP_CODE==opCode);
}

int executeIfa(int line[], int lineSize, Core *c, int *pc, bool zero){
	if(c->getAddrContent(line[0]) == DEFAULT_VAL && !zero)return UNINITIALIZED_VAR;
	if(c->getAddrContent(line[0]) == DEFAULT_VAL && zero)c->changeAddr(line[0],0.0);
	if(c->getAddrContent(line[0]) < 0){
		*pc = line[1];
	}
	else if(c->getAddrContent(line[0]) == 0){
		*pc = line[2];
	}
	else{
		*pc = line[3];
	}
	return NO_ERROR;
}