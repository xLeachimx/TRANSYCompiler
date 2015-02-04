/*FILE:tstop.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY stop commands
 *Notes:
*/
#include <string>
using std::string;
#inlcude "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with STOP
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseStop(string line);

//Precond:
//line begins with STOP
//Postcond:
//returns true iff line represents a valid stop command
int validStop(string line);
