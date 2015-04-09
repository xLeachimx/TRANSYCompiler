/*FILE:
 *Author: Michael Huelsman
 *Description:
 *   A stack of Token objects interface
 *Notes:
*/

#ifndef TOKENSTACK_HPP
#define TOKENSTACK_HPP

#include "token.hpp"

#define TOKEN_STACK_BOUND 100

class TokenStack{
public:
	TokenStack();

	//stack ops
	bool push(Token t);
	Token pop();
	Token peek();

	int size();

	bool copyContents(Token into[], int size);
protected:
private:
	Token data[TOKEN_STACK_BOUND];
	int insert;
};

#endif