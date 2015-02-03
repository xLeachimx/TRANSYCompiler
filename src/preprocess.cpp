/*FILE: preprocess.cpp
*Author: Michael Huelsman
*Description:
*	Implements the function processFile from the file preprocessor.hpp
*/
#include "preprocess.hpp"
#include <cstdio>
using std::putc;
using std::getc;

string removal(string filename);//handles all the removal and capitalization tasks
string newFilename(string filename);
char capitalize(char c);
bool isWhiteSpace(char c);

string processFile(string filename){
  return removal(filename);
}

string removal(string filename){
  FILE *input;
  FILE *output;
  input = fopen(filename.c_str(), "r");
  output = fopen(newFilename(filename).c_str(), "w");
  
  char c;
  bool protect = false; //if true what is being written it to be immedialtely put through
  bool enable = true; //if true it enables writing to the output file
  bool writtenToLine = false; //if true then something has been written on the current line
  while((c=getc(input)) != EOF){
    if(c == '\"')protect = !protect;
    if(c == '\n'){
      // Ensure that upon finishing a line that we only write a new line if we have written something
      // To the output file. Also make sure we enable writing to the output file.
      enable = true;
      if(!writtenToLine)continue;
    }
    if(!enable)continue;
    if(protect){
      // output unaltered characters
      putc(c, output);
      continue;
    }
    c = capitalize(c);
    //check for comments
    if(c == 'C'){
      c = getc(input);
      if(c == '*'){
	enable = false;
      }
      else if(c != EOF){
	putc('C', output);
	if(!isWhiteSpace(c))putc(c, output);
	if(c == '\"')protect = true;
	writtenToLine = true;
      }
    }
    else if(!isWhiteSpace(c)){
      putc(c, output);
      writtenToLine = true;
    }
    if(c == '\n')writtenToLine = false;
  }
  fclose(input);
  fclose(output);
  return newFilename(filename);
}

string newFilename(string filename){
  string name = filename.erase(filename.find(".")); // strip the filename of the extension
  name += ".nospaces";
  return name;
}

char capitalize(char c){
  // find lower case letters and adjust the ascii values to upper case
  if(c >= 97 && c <= 122){;
    c -= 32;
  }
  return c;
}

bool isWhiteSpace(char c){
  return (c == ' ' || c == '\t');
}
