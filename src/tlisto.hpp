/*FILE:tlisto.hpp
 *Author: Michael Huelsman
 *Description:
 *   parses and validated TRANSY listo commands
 *Notes:
*/

#ifndef TLISTO_HPP
#define TLISTO_HPP
#include <string>
using std::string;
#include "symtable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with LISTO
//symTable is the general symbol table
//Postcond:
//Returns a valid line of TRANSY object code representing
//the input
string parseListo(string line);

//Precond:
//line begins with LISTO
//Postcond:
//returns true iff line represents a valid listo command
int validListo(string line);

#endif