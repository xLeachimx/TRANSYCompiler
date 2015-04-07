/*FILE: earead.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a aread statement
*/

#ifndef EAREAD_HPP
#define EAREAD_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to aread's opCode
bool isAread(int opCode);

//Precond:
//  line is a series of integers representing a aread command
//  line lacks the preceeding opCode
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeAread(int line[], int lineSize, Core *c);

#endif