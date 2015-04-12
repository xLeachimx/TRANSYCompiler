/*FILE: eread.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a read statement
*/

#ifndef EREAD_HPP
#define EREAD_HPP

#include "core.hpp"


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to read's opCode
bool isRead(int opCode);

//Precond:
//  line is a series of integers representing a read command
//  line lacks the preceeding opCode of 1
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeRead(int line[], int lineSize, Core *c);

#endif