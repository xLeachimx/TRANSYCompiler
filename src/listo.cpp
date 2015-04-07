/*FILE: elisto.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in elisto.hpp
 */

#include "elisto.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define STOP_OP_CODE 3

bool isListo(int opCode){
	return (STOP_OP_CODE==opCode);
}

int executeListo(int objCode[][], int sizes[], int numLines){
	for(int i = 0;i < numLines;i++){
		for(int j = 0;j < sizes[i];i++){
			cout << objCode[i][j] << " ";
		}
		cout << endl;
	}
	return NO_ERROR;
}