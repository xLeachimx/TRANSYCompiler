/*FILE: estop.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in estop.hpp
 */

#include "ecls.hpp"
#include "validity.hpp"
#include <iostream>
using std::cout;
using std::endl;

#define CLS_OP_CODE 19

bool isCls(int opCode){
	return (CLS_OP_CODE==opCode);
}

int executeCls(){
	//preliminary clear screen attempt
	for(int i = 0;i < 100;i++){
		cout << endl;
	}
	return NO_ERROR;
}