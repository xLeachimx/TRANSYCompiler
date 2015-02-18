/*FILE: validity.hpp
*Author: Michael Huelsman
*Description:
*  Interface for functions which help determine validity of
*  Symbols and such for the TRANSY compiler
*Notes:
*  symbol length maxed to 80 such that line are kept short by the programmer without impossing rediculous limitations
*
*/

#ifndef VALIDITY_HPP
#define VALIDITY_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;


//This enum holds values for error codes such that errors can be properly diagnosed
enum ERROR_CODE{
	NO_ERROR = 0,
	BAD_ARGS,
	BAD_SYMBOLS,
	INVALID_SYMBOLS,
	EXCESS_CHARS,
};

//Precond:
// str is a vlid string
//Postcond:
// returns true iff str counts as a valid symbol in TRANSY
bool validSymbol(string str);

//Precond
// str is a valid string
//Postcond:
// returns true iff str is a valid number in TRANSY
bool validNumber(string str);

//Precond:
//  str is a valid string
//  sep is a valid character
//Postcond:
//  The returned vector is full of non-empty strings
//  which were seperated by the sep character prior
//  to processing
vector<string> split(string str, char sep=',');


// //Precond:
// //  number is a valid integer
// //Postcond:
// //  the returned string is the base ten representation of the number
// string numToStr(int number);


//Precond:
//  str is a valid string
//  c is a valid character
//Postcond:
//  Returns the amount of instances of c in str
int numberOf(string str, char c);


//Precond:
//  error is a valid member of the above enum
//Postcond:
//  The corresponing string to error will be returned
string errorString(int error);

#endif
