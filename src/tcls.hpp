/*FILE:tcls.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY cls commands
 *Notes:
*/
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with CLS
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseCls(string line);

//Precond:
//line begins with CLS
//Postcond:
//returns true iff line represents a valid cls command
int validCls(string line);
