/*FILE: elisto.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a listo statement
*/

#ifndef ELISTO_HPP
#define ELISTO_HPP

#include "executor.hpp"

//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to listo's opCode
bool isListo(int opCode);

//Precond:
//  objCode is the entrie program
//  sizes is the array of line sizes
//  numLines is the amount of lines there are
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeListo(int objCode[MAX_OBJ_LINES][MAX_OBJ_LINE_SIZE], int sizes[],int numLines);

#endif