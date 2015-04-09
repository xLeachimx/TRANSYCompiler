/*FILE:tgoto.hpp
 *Author: Michael Huelsman
 *Description:
 *  parsed and validates TRANSY goto commands
 *Notes:
*/

#ifndef TGOTO_HPP
#define TGOTO_HPP

#include <string>
using std::string;
#include "table.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with GOTO
//lineTable is the general line label tabel
//Postcond:
//Returns a valid line of TRANSY objet code representing
//the input
string parseGoto(string line, Table *lineTable);

//Precond:
//line begins with GOTO
//Postcond:
//returns true iff line represents a valid goto command
int validGoto(string line, Table *lineTable);

#endif