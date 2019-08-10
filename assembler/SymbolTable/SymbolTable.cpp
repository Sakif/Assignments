#include "SymbolTable.hpp"

void SymbolTable::addSymbol(string label, int value, SymbolType type) {
  auto node = new Symbol(label, type, value);
  table.push_back(node);
}
