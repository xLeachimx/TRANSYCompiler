/*FILE:tifa.hpp
 *Author: Michael Huelsman
 *Description:
 *  parsed and validates TRANSY ifa commands
 *Notes:
*/

#ifndef TIFA_HPP
#define TIFA_HPP

#include <string>
using std::string;
#include "table.hpp"
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with IFA
//lineTable is the general line label table
//Postcond:
//Returns a valid line of TRANSY objet code representing
//the input
string parseIfa(string line, Table *lineTable, SymTable *symTable);

//Precond:
//line begins with IFA
//Postcond:
//returns true iff line represents a valid ifa command
int validIfa(string line, Table *lineTable, SymTable *symTable);

#endif