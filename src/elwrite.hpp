/*FILE: elwrite.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a lwrite statement
*/

#ifndef ELWRITE_HPP
#define ELWRITE_HPP

#include "core.cpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to lwrite's opCode
bool isLwrite(int opCode);

//Precond:
//  line is a series of integers representing a lwrite command
//  line lacks the preceeding
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeLwrite(int line[], int lineSize, string lits[]);

#endif