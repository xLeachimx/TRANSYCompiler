/*FILE: eassignment.cpp
 *Author: Michael Huelsman
 *Description:
 *   Implemenation of the interface in eassignment.hpp
 */

#include "eassignment.hpp"
#include "validity.hpp"
#include "generalstack.hpp"

#include <cmath>
using std::pow;

#include <iostream>
using std::cout;
using std::endl;

struct assignElement{
	float value;
	bool realVal;
};
#define ASSIGNMENT_OP_CODE 20

bool isAssignment(int opCode){
	return (ASSIGNMENT_OP_CODE==opCode);
}

int executeAssignment(int line[], int lineSize, Core *c){
	GeneralStack<assignElement> execStack;
	assignElement temp;
	for(int i = 0;i < lineSize;i++){
		// cout << line[i] <<endl;
		if(line[i] < 0){
			assignElement val1;
			assignElement val2;
			if(!execStack.pop(val1))return BAD_ASSIGNMENT;
			if(!execStack.pop(val2))return BAD_ASSIGNMENT;
			switch(line[i]){
				case -1:
					// =
					if(val2.realVal)return BAD_ASSIGNMENT;
					// cout << val1.value <<endl;
					// cout << val1.value <<endl;
					if(val1.realVal){
						c->changeAddr(val2.value,val1.value);
					}
					else{
						c->changeAddr(val2.value,c->getAddrContent(val1.value));
					}
					break;
				case -2:
					// [
					if(val2.realVal)return BAD_ASSIGNMENT;
					if(val1.realVal){
						temp.value = val2.value + val1.value;
						temp.realVal = false;					
					}
					else{
						temp.value = val2.value + c->getAddrContent(val1.value);
						temp.realVal = false;
					}
					if(!execStack.push(temp))return BAD_ASSIGNMENT;
					break;
				case -3:
					// ^
					if(val1.realVal){
						if(val2.realVal){
							temp.value = pow(val2.value,val1.value);
							temp.realVal = true;
						}
						else{
							temp.value = pow(c->getAddrContent(val2.value),val1.value);
							temp.realVal = true;
						}
					}
					else{
						if(val2.realVal){
							temp.value = pow(val2.value,c->getAddrContent(val1.value));
							temp.realVal = true;
						}
						else{
							temp.value = pow(c->getAddrContent(val2.value),c->getAddrContent(val1.value));
							temp.realVal = true;
						}
					}
					if(!execStack.push(temp))return BAD_ASSIGNMENT;
					break;
				case -4:
					// *
					if(val1.realVal){
						if(val2.realVal){
							temp.value = val2.value * val1.value;
							temp.realVal = true;
						}
						else{
							temp.value = c->getAddrContent(val2.value) * val1.value;
							temp.realVal = true;
						}
					}
					else{
						if(val2.realVal){
							temp.value = val2.value * c->getAddrContent(val1.value);
							temp.realVal = true;
						}
						else{
							temp.value =  c->getAddrContent(val2.value) * c->getAddrContent(val1.value);
							temp.realVal = true;
						}
					}
					if(!execStack.push(temp))return BAD_ASSIGNMENT;
					break;
				case -5:
					// /
					if(val1.realVal){
						if(val2.realVal){
							temp.value = val2.value / val1.value;
							temp.realVal = true;
						}
						else{
							temp.value = c->getAddrContent(val2.value) / val1.value;
							temp.realVal = true;
						}
					}
					else{
						if(val2.realVal){
							temp.value = val2.value / c->getAddrContent(val1.value);
							temp.realVal = true;
						}
						else{
							temp.value =  c->getAddrContent(val2.value) / c->getAddrContent(val1.value);
							temp.realVal = true;
						}
					}
					if(!execStack.push(temp))return BAD_ASSIGNMENT;
					break;
				case -6:
					// +
					if(val1.realVal){
						if(val2.realVal){
							temp.value = val2.value + val1.value;
							temp.realVal = true;
						}
						else{
							temp.value = c->getAddrContent(val2.value) + val1.value;
							temp.realVal = true;
						}
					}
					else{
						if(val2.realVal){
							temp.value = val2.value + c->getAddrContent(val1.value);
							temp.realVal = true;
						}
						else{
							temp.value =  c->getAddrContent(val2.value) + c->getAddrContent(val1.value);
							temp.realVal = true;
						}
					}
					if(!execStack.push(temp))return BAD_ASSIGNMENT;
					break;
				case -7:
					// -
					if(val1.realVal){
						if(val2.realVal){
							temp.value = val2.value - val1.value;
							temp.realVal = true;
						}
						else{
							temp.value = c->getAddrContent(val2.value) - val1.value;
							temp.realVal = true;
						}
					}
					else{
						if(val2.realVal){
							temp.value = val2.value - c->getAddrContent(val1.value);
							temp.realVal = true;
						}
						else{
							temp.value =  c->getAddrContent(val2.value) - c->getAddrContent(val1.value);
							temp.realVal = true;
						}
					}
					// cout << "here" <<endl;
					if(!execStack.push(temp))return BAD_ASSIGNMENT;
					break;
				default:
					return BAD_ASSIGNMENT;
			}
		}
		else{
			temp.value = line[i];
			temp.realVal = false;
			execStack.push(temp);
		}
	}
	return NO_ERROR;
}