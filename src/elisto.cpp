/*FILE: elisto.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in elisto.hpp
 */

#include "elisto.hpp"
#include "validity.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define LISTO_OP_CODE 6

bool isListo(int opCode){
	return (LISTO_OP_CODE==opCode);
}

int executeListo(int objCode[MAX_OBJ_LINES][MAX_OBJ_LINE_SIZE], int sizes[], int numLines){
	cout << "=====BEGIN OBJECT CODE======" <<endl;
	for(int i = 0;i < numLines;i++){
		for(int j = 0;j < sizes[i];j++){
			cout << objCode[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=====END OBJECT CODE======" <<endl;
	return NO_ERROR;
}