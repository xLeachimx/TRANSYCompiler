/*FILE:taread.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY aread commands
 *Notes:
*/
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
string parseAread(string line, SymTable *symTable);

//Precond:
//line begins with AREAD
//Postcond:
//returns true iff line represents a valid aread command
int validAread(string line);
