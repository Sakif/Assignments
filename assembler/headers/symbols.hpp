#pragma once
#include "definitions.hpp"

using namespace std;

#ifndef SYMBOL_TYPE
#define SYMBOL_TYPE

enum SymbolType {
  UNKNOWN,
  LABEL,
  REGISTER
};

const string symbolTypeToString[] = {"UNKNOWN", "LABEL", "REGISTER"};

#endif

#ifndef SYMBOL
#define SYMBOL

struct symbol {
  string label;
  SymbolType type;
  int value;
};

#endif

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

class symbolTable {
private:
  list<symbol> table;

public:
  symbolTable();
  bool validLabel(string) const;
  symbol find(string) const;
  void printTable(ofstream &) const;

  void addSymbol(string, SymbolType, int);
};

#endif
