/*
Author: Sakif Fahmid Zaman
*/

#pragma once
#include "all.hpp"

using namespace std;

#ifndef SYMBOL
#define SYMBOL

class Symbol {
public:
  string symbolName;
  SymbolType type;
  short value;
  Symbol* nextSymbol;

  Symbol(string = "", SymbolType = UNKNOWN, short = 0, Symbol* = nullptr);

  Symbol* next() const;
  string name() const;
};

bool validLabel(string);

ostream& operator<<(ostream&, Symbol* const);
#endif

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

class SymbolTable {
private:
  Symbol* head;

public:
  SymbolTable();
  ~SymbolTable();
  void newSymbol(string, SymbolType, short);
  Symbol* begin() const;
  Symbol* find(string) const;
};

ostream& operator<<(ostream&, SymbolTable&);

#endif
