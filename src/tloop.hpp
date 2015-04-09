/*FILE:tloop.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY loop commands
 *Notes:
*/

#ifndef TLOOP_HPP
#define TLOOP_HPP

#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with LOOP
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseLoop(string line, SymTable *symTable);

//Precond:
//line begins with LOOP
//Postcond:
//returns true iff line represents a valid loop command
int validLoop(string line, SymTable *symTable);

#endif