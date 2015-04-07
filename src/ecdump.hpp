/*FILE: ecdump.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a cdump statement
*/

#ifndef ECDUMP_HPP
#define ECDUMP_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to cdump's opCode
bool isCdump(int opCode);

//Precond:
//  line is a series of integers representing a cdump command
//  line lacks the preceeding opCode of 2
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeCdump(int line[], int lineSize, Core *c);

#endif