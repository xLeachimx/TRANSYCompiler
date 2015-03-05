/*FILE:tawrite.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY awrite commands
 *Notes:
*/
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with AWRITE
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseAwrite(string line, SymTable *symTable);

//Precond:
//line begins with AWRITE
//Postcond:
//returns true iff line represents a valid awrite command
int validAwrite(string line, SymTable *symTable);
