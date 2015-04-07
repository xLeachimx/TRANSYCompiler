/*FILE: ewrite.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a write statement
*/

#ifndef EIF_HPP
#define EIF_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to if's opCode
bool isIf(int opCode);

//Precond:
//  line is a series of integers representing a if command
//  line lacks the preceeding
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeIf(int line[], int lineSize, Core *c, int *pc);

#endif