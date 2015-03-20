/*FILE: validity.cpp
*Author: Michael Huelsman
*Description:
*  Implementation of the interface laid out in validity.hpp
*Notes:
*/

#include "validity.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
using std::cout;
using std::endl;
using std::sprintf;
using std::atof;

//helper functions
bool isLetter(char c);
bool isNumber(char c);
bool isGoodSpecChar(char c);
bool isBadSpecChar(char c);


//implementation of validSymbol interface
bool validSymbol(string str){
  if(str.length() > 80)return false;
  if(isLetter(str[0])){
    for(int i = 1;i < str.length();i++){
      if(isBadSpecChar(str[i]))return false;
    }
    return true;
  }
  return false;
}

//implementation of validLiteralSymbol interface
bool validLiteralSymbol(string str){
  if(str.length() > 80)return false;
  if(str[0] != '$')return false;
  str.erase(0,1); //remove $
  return validSymbol(str);
}

//implementation of validNumber interface
bool validNumber(string str){
  if(str.size() == 1 && str == "0")return true;
  int pointCount = 0;
  bool negative = false;
  if(str[0] == '-')negative = true;
  int start = 0;
  if(negative)start = 1;
  if(!isNumber(str[start]) || str[start] == '0' )return false;
  for(int i = start+1;i < str.length();i++){
    if(str[i] == '.'){
      pointCount++;
      if(pointCount > 1)return false;
    }
    else if(!isNumber(str[i])){
      return false;
    }
  }
  return true;
}


bool isLetter(char c){
	return (c >= 'A' && c <= 'Z');
}

bool isNumber(char c){
	return (c >= '0' && c <= '9');
}

bool isGoodSpecChar(char c){
	return (c == '_');
}

bool isBadSpecChar(char c){
	return (!isLetter(c) && !isGoodSpecChar(c) && !isNumber(c));
}


//implementation of the split function
vector<string> split(string str, char sep){
	vector<string> result = vector<string>();
	while(str.length() != 0){
		int location = str.find(sep);
		if(location != 0){
			result.push_back(str.substr(0,location));
			if(location != -1)str.erase(0,location+1);
			if(location == -1)break;
		}
		else if(location == 0){
			str.erase(0,0);
		}
	}
	return result;
}

// //implementation of the numToStr function

// string numToStr(int number){
// 	cout << number <<endl;
// 	string result;
// 	int place = 0;//remembers where new digits should be placed
// 	if(number < 0){
// 		place = 1;
// 		result += "-";
// 		number = number * -1;
// 	}
// 	if(number == 0)return "0";
// 	while(number > 0){
// 		cout << result <<endl;
// 		switch(number%10){
// 		case 1:
// 			result.insert(place,1,'1');
// 			break;
// 		case 2:
// 			result.insert(place,1,'2');
// 			break;
// 		case 3:
// 			result.insert(place,1,'3');
// 			break;
// 		case 4:
// 			result.insert(place,1,'4');
// 			break;
// 		case 5:
// 			result.insert(place,1,'5');
// 			break;
// 		case 6:
// 			result.insert(place,1,'6');
// 			break;
// 		case 7:
// 			result.insert(place,1,'7');
// 			break;
// 		case 8:
// 			result.insert(place,1,'8');
// 			break;
// 		case 9:
// 			result.insert(place,1,'9');
// 			break;
// 		default:
// 			result.insert(place,1,'0');
// 			break;
// 		}
// 		number -= number%10;
// 		number = number/10;
// 	}
// 	return "";
// }

//implementation of numberOf

int numberOf(string str, char c){
	int count = 0;
	for(int i = 0;i < str.length();i++){
		if(str[i] == c)count++;
	}
	return count;
}


//implementation of errorString

string errorString(int error){
  switch(error){
  case BAD_ARGS:
    return "Bad arguments ";
  case BAD_SYMBOLS:
    return "Bad symbols ";
  case INVALID_SYMBOLS:
    return "Invalid symbols ";
  case EXCESS_CHARS:
    return "Excessive characters in line ";
  case UNDECLARED_ARRAY:
    return "Uninitialized array used ";
  case INVALID_NUMBER:
    return "Invalid number ";
  case BAD_NUMBER:
    return "Such a number or numbers cannot be used ";
  case DUPLICATE_DECLARATION:
    return "A duplicate declaration occured ";
  case BAD_LINE_LABEL:
    return "Incorrect line label ";
  case BAD_LITERAL:
    return "Incorrect literal ";
  default:
    return "Unknown Error ";
  }
}
  //implementation of standardizeNumber
string standardizeNumber(string str){
  char buffer[30];
  sprintf(buffer,"%f",atof(str.c_str()));
  str = buffer;
  return str;
}
