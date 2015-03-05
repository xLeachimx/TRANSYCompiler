/*FILE:tlwrite.hpp
 *Author: Michael Huelsman
 *Description:
 *  parses and validates TRANSY lwrite commands
 *Notes:
*/

#include <string>
using std::string;
#include "littable.hpp"

//Precond:
//line is a valid line of TRANSY code
//line begins with LWRITE
//litTable is the table for literals
//Postcond:
//Returns a valid line of TRANSY objet code representing
//the input
string parseLwrite(string line, LitTable *litTable);

//Precond:
//line begins with LWRITE
//Postcond:
//returns true iff line represents a valid lwrite command
int validLwrite(string line, LitTable *litTable);
