/*FILE:tifa.cpp
 *Author: Michael Huelsman
 *Description:
 *  Implementation of tifa.hpp
 *Notes:
*/

#include "tifa.hpp"
#include "validity.hpp"

#include <cstdio>
using std::sprintf;

//implementation of parseIfa function
string parseIfa(string line, Table *lineTable, SymTable *symTable){
  line.erase(0,3);//get rid of IFA
  string result = "10 ";
  line.erase(0,1);//removes (
  string internal = line.substr(0,line.find(')'));
  line.erase(0,line.find(')')+1);
  if(validNumber(internal))internal = standardizeNumber(internal);
  int symLoc = symTable->retrieve(internal);
  char buffer[10];
  sprintf(buffer,"%d",symLoc);
  result += buffer;
  vector<string> labels = split(line, ',');
  for(int i = 0;i < labels.size();i++){
    int lineReferred = lineTable->retrieve(labels[i]);
    sprintf(buffer,"%d",lineReferred);
    result += ' ';
    result += buffer;
  }
  return result;
}

//implementation of validIfa function
int validIfa(string line, Table *lineTable, SymTable *symTable){
  line.erase(0,3);//get rid of IFA
  if(line[0] != '(')return BAD_ARGS;
  line.erase(0,1);//removes (
  if(line.find(')') == -1)return BAD_ARGS;
  string internal = line.substr(0,line.find(')'));
  if(symTable->retrieve(internal) == -1){
    if(!validNumber(internal))return INVALID_SYMBOLS;
    internal = standardizeNumber(internal);
    if(symTable->retrieve(internal) == -1)symTable->insert(internal,1);
  }
  line.erase(0,line.find(')')+1); //get rid of already used bits
  vector<string> labels = split(line, ',');
  for(int i = 0;i < labels.size();i++){
    int lineReferred = lineTable->retrieve(labels[i]);
    if(lineReferred == -1)return BAD_LINE_LABEL;
  }
  return NO_ERROR;
}
