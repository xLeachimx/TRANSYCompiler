/*FILE: ecls.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a cls statement
*/

#ifndef ECLS_HPP
#define ECLS_HPP

//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to cls's opCode
bool isCls(int opCode);

//Precond:
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeCls();

#endif