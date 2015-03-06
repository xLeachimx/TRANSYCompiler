/*FILE: table.hpp
 *Author: Michael Huelsman
 *Description:
 *   Class description of a table ADT
 */

#ifndef TABLE_HPP
#define TABLE_HPP

#define MAX_TABLE_ENTRIES 1000

#include <string>
using std::string;

struct TableEntry{
    string symbol;
    int value;
};

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
  
  TableEntry entries[MAX_TABLE_ENTRIES];
  int insertLoc;
private:
};

#endif
