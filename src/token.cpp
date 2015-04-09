/*FILE: token.hpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of token class
*/

#include "token.hpp"

Token::Token(){
	symbol = "";
	token = "";
}

Token::Token(string s, string t){
	symbol = s;
	token = t;
}

string Token::getSymbol(){
	return symbol;
}

string Token::getToken(){
	return token;
}

Token &Token::operator=(const Token &copy){
	token = copy.token;
	symbol = copy.symbol;
	return *this;
}

bool Token::operator==(const Token &comp){
	return token==comp.token;
}