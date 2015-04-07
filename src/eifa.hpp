/*FILE: eifa.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a ifa statement
*/

#ifndef EIFA_HPP
#define EIFA_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to ifa's opCode
bool isIfa(int opCode);

//Precond:
//  line is a series of integers representing a ifa command
//  line lacks the preceeding opCode
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeIfa(int line[], int lineSize, Core *c, int *pc);

#endif