/*FILE: egoto.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in egoto.hpp
 */

#include "egoto.hpp"
#include "validity.hpp"

#define GOTO_OP_CODE 8

bool isGoto(int opCode){
	return (GOTO_OP_CODE==opCode);
}

int executeGoto(int line[], int lineSize, int *pc){
	*pc = line[0]
	return NO_ERROR;
}