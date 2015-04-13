/*FILE: esubp.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in esubp.hpp
 */

#include "esubp.hpp"
#include "validity.hpp"

#include <cmath>
using std::sin;
using std::cos;
using std::abs;
using std::exp;
using std::sqrt;
using std::log;


enum SUBP_OPERATIONS{
	SIN = 0,
	COS,
	EXP,
	ABS,
	SQR,
	ALG,
};


#define SUBP_OP_CODE 13

bool isSubp(int opCode){
	return (SUBP_OP_CODE==opCode);
}

int executeSubp(int line[], int lineSize, Core *c, bool zero){
	if(c->getAddrContent(line[1]) == DEFAULT_VAL && !zero)return UNINITIALIZED_VAR;
	if(c->getAddrContent(line[1]) == DEFAULT_VAL && zero)c->changeAddr(line[1],0.0);
	double temp = 0;
	switch(line[0]){
		case SIN:
			temp = c->getAddrContent(line[1]);
			temp = sin(temp);
			c->changeAddr(line[2],temp);
			break;
		case COS:
			temp = c->getAddrContent(line[1]);
			temp = cos(temp);
			c->changeAddr(line[2],temp);
			break;
		case EXP:
			temp = c->getAddrContent(line[1]);
			temp = exp(temp);
			c->changeAddr(line[2],temp);
			break;
		case ABS:
			temp = c->getAddrContent(line[1]);
			temp = abs(temp);
			c->changeAddr(line[2],temp);
			break;
		case SQR:
			temp = c->getAddrContent(line[1]);
			temp = sqrt(temp);
			c->changeAddr(line[2],temp);
			break;
		case ALG:
			temp = c->getAddrContent(line[1]);
			temp = log(temp);
			c->changeAddr(line[2],temp);
			break;
		default:
			return BAD_CALL;
			break;
	}
	return NO_ERROR;
}