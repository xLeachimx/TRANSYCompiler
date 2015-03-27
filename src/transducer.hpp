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
	U1,//1
	U2,//2
	U3,//3
	U4,//4
	S1,//5
	S2,//6
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