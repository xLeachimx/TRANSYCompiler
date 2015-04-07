/*FILE: eif.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eif.hpp
 */

#include "eif.hpp"
#include "validity.hpp"

#define IF_OP_CODE 18

bool isIf(int opCode){
	return (IF_OP_CODE==opCode);
}

int executeIf(int line[], int lineSize, Core *c, int *pc){
	double val1 = c->getAddrContent(line[0]);
	double val2 = c->getAddrContent(line[2]);
	switch(line[1]){
		case 0:
			//=
			if(val1 == val2)*pc = line[3];
			break;
		case 1:
			//<=
			if(val1 <= val2)*pc = line[3];
			break;
		case 2:
			//<
			if(val1 < val2)*pc = line[3];
			break;
		case 3:
			//>
			if(val1 > val2)*pc = line[3];
			break;
		case 4:
			//>=
			if(val1 >= val2)*pc = line[3];
			break;
		case 5:
			//!=
			if(val1 != val2)*pc = line[3];
			break;
		default:
			return BAD_COMPARISON;
	}
	return NO_ERROR;
}