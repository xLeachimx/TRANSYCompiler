/*FILE:tread.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY read commands
 *Notes:
*/

#ifndef TREAD_HPP
#define TREAD_HPP
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with READ
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseRead(string line, SymTable *symTable);

//Precond:
//line begins with READ
//Postcond:
//returns true iff line represents a valid read command
int validRead(string line);

#endif