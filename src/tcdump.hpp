/*FILE:tcdump.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY cdump commands
 *Notes:
*/
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with CDUMP
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseCdump(string line);

//Precond:
//line begins with CDUMP
//Postcond:
//returns true iff line represents a valid stop command
int validCdump(string line);
