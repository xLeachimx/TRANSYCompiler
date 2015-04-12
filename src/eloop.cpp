/*FILE: eloop.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eloop.hpp
 */

#include "eloop.hpp"
#include "validity.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define LOOP_OP_CODE 14

bool isLoop(int opCode){
	return (LOOP_OP_CODE==opCode);
}

int executeLoop(int line[], int lineSize, Core *c, bool seen, bool *end){
	if(c->getAddrContent(line[1]) == DEFAULT_VAL)return UNINITIALIZED_VAR;
	if(c->getAddrContent(line[2]) == DEFAULT_VAL)return UNINITIALIZED_VAR;
	if(c->getAddrContent(line[3]) == DEFAULT_VAL)return UNINITIALIZED_VAR;

	if(!seen){
		double temp = c->getAddrContent(line[1]);
		// cout << "Inside loop" <<endl;
		// cout << line[1] <<endl;
		c->changeAddr(line[0],temp);
	}
	if(c->getAddrContent(line[0]) == c->getAddrContent(line[2])){
		*end = true;
	}
	if(seen){
		double temp = c->getAddrContent(line[0]) + c->getAddrContent(line[3]);
		c->changeAddr(line[0],temp);
	}
	return NO_ERROR;
}