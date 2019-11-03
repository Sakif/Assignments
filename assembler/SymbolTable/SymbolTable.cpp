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

ErrorType SymbolTable::validLabel(string lbl) {
  auto error = NO_ERROR;
  if (lbl.length() > maxSymbolLength) return LABEL_TOO_LONG;
  if (INVALID_FIRST_CHAR(lbl.at(0))) return INVALID_FIRST_CHARACTER;
  for (auto ch : lbl)
    if (INVALID_CHAR(ch)) return INVALID_CHARACTER;
  return error;
}

Symbol *SymbolTable::find(string lbl) {
  for (auto node : table)
    if (node->getLabel() == lbl) return node;
  return nullptr;
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
