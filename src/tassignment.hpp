/*FILE:tassignment.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY assignment commands
 *Notes:
*/
#ifndef TASSIGNMENT_HPP
#define TASSIGNMENT_HPP

#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with ASSIGNMENT
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseAssignment(string line, SymTable *symTable);

//Precond:
//line begins with assignment
//Postcond:
//returns true iff line represents a valid assignment command
int validAssignment(string line, SymTable *symTable);

#endif