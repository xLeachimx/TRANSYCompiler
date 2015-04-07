/*FILE: estop.hpp
 *Author: Michael Huelsman
 *Description:
 *	Executes a stop statement
*/

#ifndef ESTOP_HPP
#define ESTOP_HPP

//Precond:
//  opCode is a valid integer
//Postcond:
//  returns true iff opCode is equal to stop's opCode
bool isStop(int opCode);

//Precond:
//Postcond:
//  returns an executor error code(as specified in validity.hpp)
//
int executeStop();

#endif