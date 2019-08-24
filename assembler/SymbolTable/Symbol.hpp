#pragma once
#include <iomanip>
#include <string>

using namespace std;

#ifndef SYMBOL_TYPE
#define SYMBOL_TYPE

enum SymbolType {
  UNKNOWN,
  LABEL,
  REGISTER
};

const string symbolTypeToString[] = {
    "UNKNOWN",
    "LABEL",
    "REGISTER"};

#endif

#ifndef SYMBOL_CONSTANTS
#define SYMBOL_CONSTANTS

const auto maxSymbolLength = 32U;
const auto maxTypeLength = symbolTypeToString[REGISTER].length();
#endif

#ifndef SYMBOL
#define SYMBOL

class Symbol {
public:
  string label;
  SymbolType type;
  int value;
  Symbol(string, SymbolType, int = 0);
  void update(SymbolType, int);

  friend ostream &operator<<(ostream &out, Symbol const &s) {
    /* label */
    out << left << setw(maxSymbolLength) << s.label << " | ";
    /* type */
    out << setw(maxTypeLength) << symbolTypeToString[s.type] << " | ";
    /* hex value */
    out << "0x" << hex << right << setfill('0') << setw(4) << s.value << " | ";
    /* decimal value */
    out << dec << s.value << setfill(' ');
    return out;
  }
};

#endif