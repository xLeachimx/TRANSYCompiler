/*FILE:twrite.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY read commands
 *Notes:
*/
#include <string>
using std::string;
#inlcude "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with READ
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseWrite(string line, SymTable &symTable);

//Precond:
//line begins with READ
//Postcond:
//returns true iff line represents a valid read command
int validWrite(string line, SymTable &symTable);
