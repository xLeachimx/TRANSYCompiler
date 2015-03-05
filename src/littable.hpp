/*FILE: littable.hpp
 *Author: Michael Huelsman
 *Description:
 *  Interface for a literal table class which inerits from the table class
 *  LitTable allows for simple insertion of literals into the table
 *Notes:
 */

#ifndef LITTABLE_HPP
#define LITTABLE_HPP

#include "table.hpp"


class LitTable: public Table{
public:
  LitTable();

  //override the insert function such that value means the location
  int insert(string symbol, int value);
protected:
private:
  int nextAddr;
};

#endif
