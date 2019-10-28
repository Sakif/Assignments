#pragma once
#include <iostream>
#include <list>
#include "Symbol.hpp"

using namespace std;

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

class SymbolTable {
 private:
  list<Symbol *> table;

 public:
  SymbolTable();
  /* ~SymbolTable(); */
  static ErrorType validLabel(string);
  Symbol *find(string);

  void addSymbol(string, int, SymbolType = UNKNOWN);

  friend ostream &operator<<(ostream &out, SymbolTable const &st) {
    out << endl;
    out << setw(80) << setfill('#') << "#" << setfill(' ') << endl;
    out << "Symbol Table; Entry Count: " << st.table.size() << endl;
    /* label */
    out << left << setw(maxSymbolLength) << "Name";
    /* type */
    out << " | " << setw(maxTypeLength) << "Type";
    /* hex value */
    out << " | " << setw(6) << "Hex";
    /* decimal value */
    out << " | Dec" << endl;
    for (auto node : st.table)
      out << *node << endl;
    return out;
  }
};

#endif