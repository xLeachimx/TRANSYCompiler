/*FILE: eifa.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eifa.hpp
 */

#include "eifa.hpp"
#include "validity.hpp"

#define IFA_OP_CODE 10

bool isIfa(int opCode){
	return (IFA_OP_CODE==opCode);
}

int executeIfa(int line[], int lineSize, Core *c, int *pc){
	if(line[0] == DEFAULT_VAL)return UNINITIALIZED_VAR;
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