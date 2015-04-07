/*FILE: eloopend.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a loop-end statement
*/

#ifndef ELOOPEND_HPP
#define ELOOPEND_HPP

//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to loop-end's opCode
bool isLoopEnd(int opCode);

//Precond:
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeLoopEnd();

#endif