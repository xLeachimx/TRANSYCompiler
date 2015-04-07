/*FILE: elwrite.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in elwrite.hpp
 */

#include "elwrite.hpp"
#include "validity.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define LWRITE_OP_CODE 17

bool isLwrite(int opCode){
	return (LWRITE_OP_CODE==opCode);
}

int executeLwrite(int line[], int lineSize, string lits[]){
	cout << c->getAddrContent(lits[line[0]]) << endl;
	return NO_ERROR;
}