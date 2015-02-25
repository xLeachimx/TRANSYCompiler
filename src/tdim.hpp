/*FILE:tdim.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY dim commands
 *Notes:
*/
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with DIM
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseDim(string line, SymTable *symTable);

//Precond:
//line begins with DIM
//Postcond:
//returns true iff line represents a valid dim command
int validDim(string line, SymTable *symTable);
