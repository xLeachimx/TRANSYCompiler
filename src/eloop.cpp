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

int executeLoop(int line[], int lineSize, Core *c, bool seen, bool *end, bool zero){
	cout << "Values:" <<endl;
	cout << line[1] <<endl;
	cout << c->getAddrContent(line[1]) <<endl;
	cout << line[2] <<endl;
	cout << c->getAddrContent(line[2]) <<endl;
	cout << line[3] <<endl;
	cout << c->getAddrContent(line[3]) <<endl;
	if(c->getAddrContent(line[1]) == DEFAULT_VAL && !zero)return UNINITIALIZED_VAR;
	if(c->getAddrContent(line[1]) == DEFAULT_VAL && zero)c->changeAddr(line[1],0.0);
	if(c->getAddrContent(line[2]) == DEFAULT_VAL && !zero)return UNINITIALIZED_VAR;
	if(c->getAddrContent(line[2]) == DEFAULT_VAL && zero)c->changeAddr(line[2],0.0);
	if(c->getAddrContent(line[3]) == DEFAULT_VAL && !zero)return UNINITIALIZED_VAR;
	if(c->getAddrContent(line[3]) == DEFAULT_VAL && zero)c->changeAddr(line[3],0.0);

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