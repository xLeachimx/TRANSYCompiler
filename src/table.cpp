/*FILE: table.cpp
 *Author: Michael Huelsman
 *Description:
 *   An implementation of the interface described in table.hpp
 */

#include "table.hpp"

//creates an empty useless table
Table::Table(){
  insertLoc = 0;
}

Table::~Table(){
  insertLoc = 0;
}

int Table::retrieve(string symbol){
  int loc = location(symbol);
  return (loc == -1)?-1:entries[loc].value;
}

int Table::insert(string symbol, int value){
  if(insertLoc >= MAX_TABLE_ENTRIES)return -1;
  TableEntry temp;
  temp.symbol = symbol;
  temp.value = value;
  entries[insertLoc++] = temp;
  return value;
}

int Table::operator[](string symbol){
  int loc = location(symbol);
  return (loc == -1)?-1:entries[loc].value; //using bad access here because we are returning a reference not a copy
}

//protected

//returns the location of the symbol in the array
int Table::location(string symbol){
  for(int i = 0;i < insertLoc;i++){
    if(symbol == entries[i].symbol)return i;
  }
  return -1;
}
