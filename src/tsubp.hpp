/*FILE:tsubp.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY subp commands
 *Notes:
*/

#ifndef TSUBP_HPP
#define TSUBP_HPP
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with SUBP
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseSubp(string line, SymTable *symTable);

//Precond:
//line begins with SUBP
//Postcond:
//returns true iff line represents a valid subp command
int validSubp(string line, SymTable *symTable);

#endif