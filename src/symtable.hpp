/*FILE: symtable.hpp
 *Author: Michael Huelsman
 *Description:
 *  Interface for a symbol table class which inerits from the table class
 *  SymTable allows for simple insertion of symbols into the table
 *Notes:
 */

#ifndef SYMTABLE_HPP
#define SYMTABLE_HPP

#include "table.hpp"
#include "core.hpp"


class SymTable: public Table{
public:
  SymTable();

  //override the insert function such that value means the number of core address taken
  int insert(string symbol, int value);

  //generates a core instance that reflects the symbol table
  Core genCore();
protected:
private:
  int nextAddr;
};

#endif
