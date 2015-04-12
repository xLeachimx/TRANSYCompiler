/*FILE: eassignment.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a assignment statement
*/

#ifndef EASSIGNMENT_HPP
#define EASSIGNMENT_HPP

#include "core.hpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to assignment's opCode
bool isAssignment(int opCode);

//Precond:
//  line is a series of integers representing a assignment command
//  line lacks the preceeding opCode
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeAssignment(int line[], int lineSize, Core *c);

#endif