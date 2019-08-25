#pragma once
#include "definitions.hpp"
#include <iomanip>

using namespace std;

#ifndef SYMBOL
#define SYMBOL

class Symbol {
private:
  string label;
  SymbolType type;
  int value;

public:
  Symbol(string, SymbolType, int = 0);
  void update(SymbolType, int);

  string getLabel() const;
  string printType() const;
  SymbolType getType() const;
  int getValue() const;

  friend ostream &operator<<(ostream &out, Symbol const &s) {
    /* label */
    out << left << setw(maxSymbolLength) << s.getLabel() << " | ";
    /* type */
    out << setw(maxTypeLength) << s.printType() << " | ";
    /* hex value */
    out << "0x" << hex << right << setfill('0') << setw(4) << s.getValue() << " | ";
    /* decimal value */
    out << dec << s.getValue() << setfill(' ');
    return out;
  }
};

#endif