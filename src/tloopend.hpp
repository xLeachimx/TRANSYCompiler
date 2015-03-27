/*FILE:tloopend.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY loop-end commands
 *Notes:
*/

#ifndef TLOOPEND_HPP
#define TLOOPEND_HPP

#include <string>
using std::string;

//Precond:
//line is a valid line of TRANSY code
//line begins with LOOP-END
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseLoopend(string line);

//Precond:
//line begins with LOOP-END
//Postcond:
//returns true iff line represents a valid loop-end command
int validLoopend(string line);

#endif