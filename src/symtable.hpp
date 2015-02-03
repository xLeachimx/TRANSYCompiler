/*FILE: symtable.hpp
 *Author: Michael Huelsman
 *Description:
 *  Interface for a symbol table class which inerits from the table class
 *Notes:
 */

#ifndef SYMTABLE_HPP
#define SYMTABLE_HPP

#include "table.hpp"


class SymTable: public Table{
public:
  SymTable();
  int nextCoreAddr();//returns the next core memory address
protected:
private:
  int nextAddr;
};

#endif
