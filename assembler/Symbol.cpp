#include "Symbol.hpp"

using namespace std;

Symbol::Symbol(string l, SymbolType t, int v, Symbol *next) : label(l), type(t), value(v), nextSymbol(next) {}

int Symbol::getValue() const {
  return value;
}

bool Symbol::inUnknown() const {
  return type == UNKNOWN;
}

void Symbol::update(int v, SymbolType t) {
  value = v;
  type = t;
}

string Symbol::getLabel() const {
  return label;
}

string Symbol::printType() const {
  return symbolTypeToString[type];
}
