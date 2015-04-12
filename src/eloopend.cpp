/*FILE: eloopend.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eloopend.hpp
 */

#include "eloopend.hpp"
#include "validity.hpp"

#define LOOP_END_OP_CODE 15

bool isLoopEnd(int opCode){
	return (LOOP_END_OP_CODE==opCode);
}

int executeLoopEnd(){
	return NO_ERROR;
}