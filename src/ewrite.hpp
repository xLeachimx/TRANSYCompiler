/*FILE: ewrite.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a write statement
*/

#ifndef EWRITE_HPP
#define EWRITE_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to write's opCode
bool isWrite(int opCode);

//Precond:
//  line is a series of integers representing a write command
//  line lacks the preceeding opCode of 2
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeWrite(int line[], int lineSize, Core *c);

#endif