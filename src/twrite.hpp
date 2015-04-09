/*FILE:twrite.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY write commands
 *Notes:
*/

#ifndef TWRITE_HPP
#define TWRITE_HPP
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with WRITE
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseWrite(string line, SymTable *symTable);

//Precond:
//line begins with READ
//Postcond:
//returns true iff line represents a valid write command
int validWrite(string line);

#endif