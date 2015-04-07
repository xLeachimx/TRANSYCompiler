/*FILE: eawrite.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes an awrite statement
*/

#ifndef EAWRITE_HPP
#define EAWRITE_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to awrite's opCode
bool isAwrite(int opCode);

//Precond:
//  line is a series of integers representing a awrite command
//  line lacks the preceeding opCode
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeAwrite(int line[], int lineSize, Core *c);

#endif