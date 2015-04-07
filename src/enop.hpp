/*FILE: enop.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a nop statement
*/

#ifndef ENOP_HPP
#define ENOP_HPP

//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to stop's opCode
bool isNop(int opCode);

//Precond:
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeNop();

#endif