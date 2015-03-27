/*FILE: token.cpp
 *Author: Michael Huelsman
 *Description:
 *  A class which holds both the original symbol as well as the token value
 *  For said symbol
*/

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
using std::string;

class Token{
public:
	Token();
	Token(string s, string t);

	string getSymbol();
	string getToken();

	Token &operator=(const Token &copy);

	bool operator==(const Token &comp);
protected:
private:
	string symbol;
	string token;
};

#endif