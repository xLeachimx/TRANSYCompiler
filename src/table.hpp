/*FILE: table.hpp
 *Author: Michael Huelsman
 *Description:
 *   Class description of a table ADT
 */

#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
using std::string;

class Table{
public:
  Table();
  Table(int size);
  ~Table();
  int retrieve(string symbol);
  int insert(string symbol, int value);

  int operator[](string symbol);
protected:
  void createNewNode(string symbol, int value);
  int location(string symbol);
private:
  struct TableEntry{
    string symbol;
    int value;
  };

  TableEntry *entries;
  int size;
  int insertLoc;
};

#endif