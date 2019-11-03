#include "Symbol.hpp"

using namespace std;

Symbol::Symbol(string l, SymbolType t, int v) : label(l), type(t), value(v) {}

void Symbol::update(SymbolType t, int v) {
  type = t;
  value = v;
}

string Symbol::getLabel() const { return label; }

SymbolType Symbol::getType() const { return type; }

string Symbol::printType() const { return symbolTypeToString[getType()]; }

int Symbol::getValue() const { return value; }
