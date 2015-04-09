/*FILE: transducer.cpp
 *Author: Michael Huelsman
 *Description:
 *  A implementation of the interface in transducer.hpp
*/

#include "transducer.hpp"
Transducer::Transducer(){
	insert = 0;
}

void Transducer::addRule(Rule r){
	rules[insert++] = r;
}

int Transducer::getAction(Token input, Token topStack){
	for(int i = 0;i < insert;i++){
		if(rules[i].input == input && rules[i].topStack == topStack)return rules[i].action;
	}
	return BAD_ACTION;
}
