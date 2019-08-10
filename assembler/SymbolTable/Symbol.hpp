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

const string symbolTypeToString[] = {"UNKNOWN", "LABEL", "REGISTER"};

#endif

#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol {
private:
  string label;
  SymbolType type;
  int value;

public:
  Symbol(string, SymbolType, int);
  ~Symbol();

  string getLabel() const;
  int getValue() const;
  bool inUnknown() const;
  string printType() const;
  void update(int, SymbolType);
};

#endif
