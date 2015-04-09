/*FILE: elread.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in elread.hpp
 */

#include "elread.hpp"
#include "validity.hpp"

#include <iostream>
#include <string>
using std::getline;
using std::cin;

#define LWRITE_OP_CODE 16

bool isLwrite(int opCode){
	return (LWRITE_OP_CODE==opCode);
}

int executeLwrite(int line[], int lineSize, string lits[]){
	getline(cin,lits[line[1]]);
	return NO_ERROR;
}