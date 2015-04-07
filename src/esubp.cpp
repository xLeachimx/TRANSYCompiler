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
using std::sqr;
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

int executeSubp(int line[], int lineSize, Core *c){
	if(line[1] == DEFAULT_VAL)return UNINITIALIZED_VAR;
	switch(line[0]){
		case SIN:
			double temp = c->getAddrContent(line[1]);
			temp = sin(temp);
			c->changeAddr(line[2],temp);
			break;
		case COS:
			double temp = c->getAddrContent(line[1]);
			temp = cos(temp);
			c->changeAddr(line[2],temp);
			break;
		case EXP:
			double temp = c->getAddrContent(line[1]);
			temp = exp(temp);
			c->changeAddr(line[2],temp);
			break;
		case ABS:
			double temp = c->getAddrContent(line[1]);
			temp = abs(temp);
			c->changeAddr(line[2],temp);
			break:
		case SQR:
			double temp = c->getAddrContent(line[1]);
			temp = sqr(temp);
			c->changeAddr(line[2],temp);
			break;
		case ALG:
			double temp = c->getAddrContent(line[1]);
			temp = log(temp);
			c->changeAddr(line[2],temp);
			break;
		case default:
			return BAD_CALL;
			break;
	}
	return NO_ERROR;
}