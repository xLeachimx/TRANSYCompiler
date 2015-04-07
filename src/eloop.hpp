/*FILE: eloop.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a eloop statement
*/

#ifndef ELOOP_HPP
#define ELOOP_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to loop's opCode
bool isLoop(int opCode);

//Precond:
//  line is a series of integers representing a loop command
//  line lacks the preceeding opCode
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeLoop(int line[], int lineSize, Core *c, bool seen, bool *end);

#endif