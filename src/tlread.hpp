/*FILE:tlread.hpp
 *Author: Michael Huelsman
 *Description:
 *  parsed and validates TRANSY lread commands
 *Notes:
*/

#ifndef TLREAD_HPP
#define TLREAD_HPP

#include <string>
using std::string;
#include "littable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with LREAD
//litTable is the table for literals
//Postcond:
//Returns a valid line of TRANSY objet code representing
//the input
string parseLread(string line, LitTable *litTable);

//Precond:
//line begins with LREAD
//Postcond:
//returns true iff line represents a valid lread command
int validLread(string line, LitTable *litTable);

#endif