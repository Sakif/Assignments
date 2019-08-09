#pragma once
#include "Symbol.hpp"

using namespace std;

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

class SymbolTable {
private:
  Symbol *head;

public:
  SymbolTable();
  ~SymbolTable();
  void addSymbol(string);

  friend std::ostream &operator<<(std::ostream &, SymbolTable const &);
};

#endif

SymbolTable::SymbolTable() {
  auto reg = new Symbol("R0", REGISTER, 0, head);
  head = reg;
}

ostream &operator<<(ostream &out, SymbolTable const &s) {
  return out;
}
