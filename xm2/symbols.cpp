/*
Author: Sakif Fahmid Zaman
*/

#include "all.hpp"

using namespace std;

Symbol::Symbol(string n, SymbolType t, short v, Symbol* next) {
  symbolName = n;
  type = t;
  value = v;
  nextSymbol = next;
}

Symbol* Symbol::next() const { return nextSymbol; }

string Symbol::name() const { return symbolName; }

void SymbolTable::newSymbol(string name, SymbolType type, short value) {
  auto node = new Symbol(name, type, value, head->next());
  head->nextSymbol = node;
};

SymbolTable::SymbolTable() {
  head = new Symbol();
  newSymbol("R0", REGISTER, 0);
  newSymbol("R1", REGISTER, 1);
  newSymbol("R2", REGISTER, 2);
  newSymbol("R3", REGISTER, 3);
  newSymbol("R4", REGISTER, 4);
  newSymbol("R5", REGISTER, 5);
  newSymbol("R6", REGISTER, 6);
  newSymbol("R7", REGISTER, 7);
}

Symbol* SymbolTable::begin() const { return head->next(); }

ostream& operator<<(ostream& out, Symbol* const s) {
  if (s == nullptr)
    out << err << "Symbol does not exist.";
  else {
    out << setw(MAX_LABEL_LENGTH) << left << s->name();
    out << " | " << setw(8) << SymbolTypeToString[s->type];
    out << " | " << right << setw(5) << s->value;
    out << " (0x" << hex << setw(4) << setfill('0') << s->value;
    out << ")" << setfill(' ') << dec;
    if (s->type == UNKNOWN) out << "\t" << err << "Table contains unknown symbol.";
  }
  return out;
}

SymbolTable::~SymbolTable() {
  auto itr = head;
  while (itr != nullptr) {
    auto temp = itr;
    itr = itr->next();
    delete temp;
  }
}

ostream& operator<<(ostream& out, SymbolTable& st) {
  out << endl;
  out << "####################### SYMBOL TABLE #######################" << endl;
  out << "              NAME               |   TYPE   |     VALUE     " << endl;
  out << "============================================================" << endl;
  for (auto node = st.begin(); node != nullptr; node = node->next()) out << node << endl;
  return out;
}

bool validLabel(string l) {
  auto valid = true;
  if (l.length() > MAX_LABEL_LENGTH) return false;
  if (!ALPHABETIC(l[0])) return false;
  for (auto c : l)
    if (!ALPHANUMERIC(c)) return false;
  return valid;
}

Symbol* SymbolTable::find(string label) const {
  for (auto itr = begin(); itr != nullptr; itr = itr->next())
    if (itr->name() == label) return itr;
  return nullptr;
}

bool duplicateSymbol() { return false; }
