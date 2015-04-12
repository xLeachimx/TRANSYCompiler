/*FILE: egoto.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a goto statement
*/

#ifndef EGOTO_HPP
#define EGOTO_HPP

#include "core.hpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to goto's opCode
bool isGoto(int opCode);

//Precond:
//  line is a series of integers representing a goto command
//  line lacks the preceeding opCode of 2
//  line Size is the number of elements in the line
//  pc is the program counter
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeGoto(int line[], int lineSize, int *pc);

#endif