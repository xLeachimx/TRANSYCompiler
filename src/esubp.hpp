/*FILE: esubp.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a subp statement
*/

#ifndef ESUBP_HPP
#define ESUBP_HPP

#include "core.hpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to subp's opCode
bool isSubp(int opCode);

//Precond:
//  line is a series of integers representing a subp command
//  line lacks the preceeding opCode
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeSubp(int line[], int lineSize, Core *c);

#endif