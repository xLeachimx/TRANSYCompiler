/*FILE: transducer.hpp
 *Author: Michael Huelsman
 *Description:
 *  A class which enacts a transducer table
*/

#ifndef TRANSDUCER_HPP
#define TRANSDUCER_HPP

#include "token.hpp"
#include <string>
using std::string;

#define OPERATORS 10

enum ACTION{
	BAD_ACTION,
	U1,
	U2,
	U3,
	U4,
	S1,
	S2,
};

struct Rule{
	Token topStack;
	Token input;
	int action;
};

class Transducer{
public:
	Transducer();

	void addRule(Rule r);

	int getAction(Token input, Token topStack);
protected:
private:
	Rule rules[OPERATORS*OPERATORS];
	int insert;
};

#endif