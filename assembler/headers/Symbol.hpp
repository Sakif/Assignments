#pragma once
#include <string>

using namespace std;

#ifndef SYMBOL_TYPE
#define SYMBOL_TYPE

enum SymbolType {
  UNKNOWN,
  LABEL,
  REGISTER
};

const string symbolTypeToString[] = {"UNK", "LBL", "REG"};

#endif

#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol {
private:
  string label;
  SymbolType type;
  int value;
  Symbol *nextSymbol;

public:
  Symbol(string, SymbolType, int, Symbol *);
  ~Symbol();

  string getLabel() const;
  int getValue() const;
  bool inUnknown() const;
  string printType() const;
  void update(int, SymbolType);
};

#endif
