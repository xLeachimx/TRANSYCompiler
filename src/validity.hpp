/*FILE: validity.hpp
*Author: Michael Huelsman
*Description:
*  Interface for functions which help determine validity of
*  Symbols and such for the TRANSY compiler
*Notes:
*/

#ifndef VALIDITY_HPP
#define VALIDITY_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

//Precond:
// str is a vlid string
//Postcond:
// returns true iff str counts as a valid symbol in TRANSY
bool validSymbol(string str);

//Precond:
//  str is a valid string
//  sep is a valid character
//Postcond:
//  The returned vector is full of non-empty strings
//  which were seperated by the sep character prior
//  to processing
vector<string> split(string str, char sep=',');


//Precond:
//  number is a valid integer
//Postcond:
//  the returned string is the base ten representation of the number
string numToStr(int number);

#endif
