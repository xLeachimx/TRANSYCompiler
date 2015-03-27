/*FILE:tnop.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY nop commands
 *Notes:
*/

#ifndef TNOP_HPP
#define TNOP_HPP

#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with NOP
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseNop(string line);

//Precond:
//line begins with NOP
//Postcond:
//returns true iff line represents a valid nop command
int validNop(string line);

#endif