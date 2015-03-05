/*FILE: preprocess.hpp
 *Author: Michael Huelsman
 *Description:
 *   A simple preprocessor for the TRANSY language
 */

#ifndef PREPROCESS_HPP
#define PREPROCESS_HPP

#include "table.hpp"
#include <string>
using std::string;

//Precondition:
//   filename is a string which contains a valid file to perform
//      TRANSY preprocessing on.
//Postcondition:
//   The return value is the filename of a file where all comments and spaces
//      have been removed along with all letters being capitalized 
string processFile(string filename, Table lineLabels);

#endif
