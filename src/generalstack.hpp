/*FILE: generalstack.hpp
 *Author: Michael Huelsman
 *Description:
 *   A general stack
*/

#ifndef GENERALSTACK_HPP
#define GENERALSTACK_HPP

#define MAX_STACK_SIZE 100

template<class X> class GeneralStack{
public:
	GeneralStack<X>();
	bool push(X val);
	bool pop(X &val);
	bool peek(X &val);
protected:
private:
	int size;
	X stack[MAX_STACK_SIZE];
};

template<class X> GeneralStack<X>::GeneralStack(){
	size = 0;
}

template<class X> bool GeneralStack<X>::push(X val){
	if(size == MAX_STACK_SIZE)return false;
	stack[size++] = val;
	return true;
}

template<class X> bool GeneralStack<X>::pop(X &val){
	if(stack == 0)return false;
	val = stack[--size];
	return true;
}

template<class X> bool GeneralStack<X>::peek(X &val){
	if(stack == 0)return false;
	val = stack[size-1];
	return true;
}

#endif