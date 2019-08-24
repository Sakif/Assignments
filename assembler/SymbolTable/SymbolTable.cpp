#include "SymbolTable.hpp"

SymbolTable::SymbolTable() {
  addSymbol("R0", 0, REGISTER);
  addSymbol("R1", 1, REGISTER);
  addSymbol("R2", 2, REGISTER);
  addSymbol("R3", 3, REGISTER);
  addSymbol("R4", 4, REGISTER);
  addSymbol("R5", 5, REGISTER);
  addSymbol("R6", 6, REGISTER);
  addSymbol("R7", 7, REGISTER);
}

void SymbolTable::addSymbol(string label, int value, SymbolType type) {
  auto node = new Symbol(label, type, value);
  table.push_front(node);
}

/*
SymbolTable::~SymbolTable() {
  while (head != nullptr) {
    auto temp = head;
    head = head->next();
    delete temp;
  }
}
*/
