/* see symbol.md */

#ifndef SYMBOL_TYPE
#define SYMBOL_TYPE
enum symbolType { UNKNOWN,
                  REGISTER,
                  LABEL };

#endif

#ifndef SYMBOL
#define SYMBOL

#pragma once
#include <string>

class symbol {
public:
  string name;
  short value;
  symbolType type;
  symbol *next;

  symbol(string, short, symbolType, symbol * = nullptr);
  void update(short, symbolType);
};

symbol::symbol(string n, short v, symbolType t, symbol *nextSymbol) : name(n), value(v), type(t), next(nextSymbol) {}

void symbol::update(short v, symbolType t) {
  value = v;
  type = t;
}

#endif