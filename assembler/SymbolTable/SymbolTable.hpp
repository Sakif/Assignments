#pragma once
#include "Symbol.hpp"
#include <list>

using namespace std;

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

class SymbolTable {
private:
  list<Symbol *> table;

public:
  SymbolTable();
  ~SymbolTable();
  void addSymbol(string, int, SymbolType);
};

#endif
