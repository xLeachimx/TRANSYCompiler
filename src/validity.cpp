/*FILE: validity.cpp
*Author: Michael Huelsman
*Description:
*  Implementation of the interface laid out in validity.hpp
*Notes:
*/

//helper functions
bool isLetter(char c);
bool isNumber(char c);
bool isGoodSpecChar(char c)
bool isBadSpecChar(char c);


//implementation of validSymbol interface
bool validSymbol(string str){
  if(isLetter(str[0])){
    for(int i = 1;i < str.length();i++){
      if(isBadSpecChar())return false;
    }
    return true;
  }
  return false;
}


bool isLetter(char c){
  return (c >= 'A' && c <= 'Z')
}

bool isNumber(char c){
  return (c >= '0' && c <= '9');
}

bool isGoodSpecChar(char c){
  return (c == '_')
}

bool isBadSpecChar(char c){
  return (!isLetter(c) && !isGoodSpecChar(c) && !isNumber(c))
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

//implementation of the numToStr function

string numToStr(int number){
  string result;
  int place = 0;//remembers where new digits should be placed
  if(number < 0){
    place = 1;
    result += "-";
    number = number * -1;
  }
  while(number > 0){
    switch(number%10){
    case 1:
      result.insert(place,1,'1');
      break;
    case 2:
      result.insert(place,1,'2')
      break;
    case 3:
      result.insert(place,1,'3')
      break;
    case 4:
      result.insert(place,1,'4')
      break;
    case 5:
      result.insert(place,1,'5')
      break;
    case 6:
      result.insert(place,1,'6')
      break;
    case 7:
      result.insert(place,1,'7')
      break;
    case 8:
      result.insert(place,1,'8')
      break;
    case 9:
      result.insert(place,1,'9')
      break;
    default:
      result.insert(place,1,'0')
      break;
    }
    number -= number%10;
  }
}