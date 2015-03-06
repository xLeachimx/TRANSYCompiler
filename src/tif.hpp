/*FILE:tif.hpp
 *Author: Michael Huelsman
 *Description:
 *  parsed and validates TRANSY if commands
 *Notes:
*/

#include <string>
using std::string;
#include "table.hpp"
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with IF
//lineTable is the general line label table
//Postcond:
//Returns a valid line of TRANSY objet code representing
//the input
string parseIf(string line, Table *lineTable, SymTable *symTable);

//Precond:
//line begins with IF
//Postcond:
//returns true iff line represents a valid if command
int validIf(string line, Table *lineTable, SymTable *symTable);
