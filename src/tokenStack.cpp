/*FILE: tokenStack.cpp
 *Author: Michael Huelsman
 *Description:
 *   An implementation of the token stack 
 *Notes:
*/

#include "tokenStack.hpp"

TokenStack::TokenStack(){
	insert = 0;
}

//stack ops
bool TokenStack::push(Token t){
	if(insert >= TOKEN_STACK_BOUND) return false;
	data[insert++] = t;
	return true;
}

Token TokenStack::pop(){
	if(insert > 0)return data[--insert];
	Token temp("INVALID","INVALID");
	return temp;
}

Token TokenStack::peek(){
	if(insert > 0)return data[insert-1];
	Token temp("INVALID","INVALID");
	return temp;
}

int TokenStack::size(){
	return insert;
}

bool TokenStack::copyContents(Token into[], int size){
	if(insert > size)return false;
	for(int i = 0;i < size;i++){
		into[i] = data[i];
	}
	return true;
}