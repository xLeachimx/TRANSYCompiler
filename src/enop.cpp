/*FILE: enop.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in enop.hpp
 */

#include "enop.hpp"
#include "validity.hpp"

#define NOP_OP_CODE 7

bool isNop(int opCode){
	return (NOP_OP_CODE==opCode);
}

int executeNop(){
	return NO_ERROR;
}