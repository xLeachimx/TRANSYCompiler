/*FILE: estop.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in estop.hpp
 */

#include "estop.hpp"

#define STOP_OP_CODE 3

bool isStop(int opCode){
	return (STOP_OP_CODE==opCode);
}

int executeStop(){
	return NO_ERROR;
}