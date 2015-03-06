/*FILE:tif.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of tif.hpp
 *Notes:
*/

#include "tif.hpp"
#include "validity.hpp"

#include <cstdio>
using std::sprintf;

//implementation of parseIf function
string parseIf(string line, Table *lineTablem, SymTable *symTable){
  line.erase(0,2);//get rid of IF
  result = "18 ";
  line.erase(0,1);//removes (
  string internal = line.substr(0,line.find(')'));
  line.erase(0,line.find(')')+1);
  int opLoc = -1;
  int comp = -1;
  string symOne = "";
  string symTwo = "";
  if((opLoc=line.find("=")) != -1){
    symOne = line.substr(0,opLoc);
    comp = 0;
    line.erase(0,opLoc+1);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find("<=")) != -1){
    symOne = line.substr(0,opLoc);
    comp = 1;
    line.erase(0,opLoc+2);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find("<")) != -1){
    symOne = line.substr(0,opLoc);
    comp = 2;
    line.erase(0,opLoc+1);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find(">=")) != -1){
    symOne = line.substr(0,opLoc);
    comp = 3;
    line.erase(0,opLoc+2);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')'+1);
  }
  else if((opLoc=line.find(">")) != -1){
    symOne = line.substr(0,opLoc);
    comp = 4;
    line.erase(0,opLoc+1);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find("!=")) != -1){
    symOne = line.substr(0,opLoc);
    comp = 5;
    line.erase(0,opLoc+2);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.fins(')')+1);
  }
  symLoc = symTable->retrieve(symOne);
  char buffer[10];
  sprintf(buffer,"%d",symLoc);
  result += buffer;
  sprintf(buffer,"%d",comp);
  result += ' ';
  result += buffer;
  symLoc = symTable->retrieve(symTwo);
  sprintf(buffer,"%d",symLoc);
  result += ' ';
  result += buffer;
  line.erase(0,4);//remove THEN
  int lineReferred = lineTable->retrieve(line);
  sprintf(buffer,"%d",lineReferred);
  result += ' ';
  result += buffer;
  return result;
}

//implementation of validIf function
int validIf(string line, Table *lineTable, SymTable *symTable){
  line.erase(0,2);//get rid of IF
  if(line[0] != ')')return BAD_ARGS;
  line.erase(0,1);//removes (
  string internal = line.substr(0,line.find(')'));
  line.erase(0,line.find(')')+1);
  int opLoc = -1;
  string symOne = "";
  string symTwo = "";
  if((opLoc=line.find("=")) != -1){
    symOne = line.substr(0,opLoc);
    line.erase(0,opLoc+1);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find("<=")) != -1){
    symOne = line.substr(0,opLoc);
    line.erase(0,opLoc+2);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find("<")) != -1){
    symOne = line.substr(0,opLoc);
    line.erase(0,opLoc+1);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find(">=")) != -1){
    symOne = line.substr(0,opLoc);
    line.erase(0,opLoc+2);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')'+1);
  }
  else if((opLoc=line.find(">")) != -1){
    symOne = line.substr(0,opLoc);
    line.erase(0,opLoc+1);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.find(')')+1);
  }
  else if((opLoc=line.find("!=")) != -1){
    symOne = line.substr(0,opLoc);
    line.erase(0,opLoc+2);
    symTwo = line.substr(0,line.find(')'));
    line.erase(0,line.fins(')')+1);
  }
  else{
    return BAD_ARGS;
  }
  if(!validSymbol(symOne)){
    if(!validNumber(symOne))return BAD_ARGS;
    if(symTable->retrieve(symOne) == -1)symTable->insert(standardizeNumber(symOne),1);
  }
  else{
    if(symTable->retrieve(symOne) == -1)return INVALID_SYMBOL;
  }
  if(!validSymbol(symTwo)){
    if(!validNumber(symTwo))return BAD_ARGS;
    if(symTable->retrieve(symTwo) == -1)symTable->insert(standardizeNumber(symTwo),1);
  }
  else{
    if(symTable->retrieve(symTwo) == -1)return INVALID_SYMBOL;
  }
  symLoc = symTable->retrieve(symTwo);
  if(line.substr(0,4) != "THEN")return BAD_ARGS;
  line.erase(0,4);//remove THEN
  if(lineTable->retrieve(line) == -1)BAD_LINE_LABEL;
  return NO_ERROR;
}
