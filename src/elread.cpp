/*FILE: elread.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in elread.hpp
 */

#include "elread.hpp"
#include "validity.hpp"

#include <iostream>
#include <string>
#include <climits>
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

#define LREAD_OP_CODE 16

bool isLread(int opCode){
	return (LREAD_OP_CODE==opCode);
}

int executeLread(int line[], int lineSize, string lits[]){
	char temp[100];
	cin.ignore(INT_MAX,'\n');
	//cin.ignore(INT_MAX, '\n'); //solution from http://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
	cin.getline(temp,100);
	lits[line[0]] = temp;
	return NO_ERROR;
}
