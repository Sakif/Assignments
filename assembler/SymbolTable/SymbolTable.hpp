#pragma once
#include "Symbol.hpp"
#include <iostream>
#include <list>

using namespace std;

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

class SymbolTable {
private:
  Symbol *head;

public:
  SymbolTable();
  /* ~SymbolTable(); */

  void addSymbol(string, int, SymbolType);
  friend ostream &operator<<(ostream &, SymbolTable const &);
};

ostream &operator<<(ostream &out, SymbolTable const &table) {
  out << "Symbol Table" << endl;
  auto node = table.head;
  out << node->getLabel() << endl;
  return out;
}

#endif
