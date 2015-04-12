/*FILE: elwrite.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a lwrite statement
*/

#ifndef ELREAD_HPP
#define ELREAD_HPP

#include <string>
using std::string;


//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to lread's opCode
bool isLread(int opCode);

//Precond:
//  line is a series of integers representing a lread command
//  line lacks the preceeding
//  line Size is the number of elements in the line
//  Core is the current Core in use
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeLread(int line[], int lineSize, string lits[]);

#endif