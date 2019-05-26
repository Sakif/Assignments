#include "splitString.hpp"
#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

enum symbolType { UNKNOWN,
                  REGISTER,
                  LABEL };

class symbolTable {
public:
  class symbol {
  public:
    string name;
    int value;
    symbolType type;

    symbol(string, int, symbolType);
    void print();
  };

  list<symbol> symbolList;

  symbolTable();

  bool validSymbol(string, int, string = "assembler.log");
  void printTable();
};

symbolTable::symbol::symbol(string n, int v, symbolType t) {
  name = n;
  value = v;
  type = t;
}

void symbolTable::symbol::print() {
  ofstream csv("symbol.csv");
  csv << name << "," << value << "," << type << endl;
  csv.close();
}

symbolTable::symbolTable() {
  ifstream startSymbols("StartSymbols.csv");
  string name = "", line = "";
  auto value = 0;
  symbolType type = UNKNOWN;
  auto s = new symbol(name, value, type);
  while (getline(startSymbols, line)) {
    auto tokens = splitString(line, ",");
    for (auto i : tokens)
      cout << i << endl;
  }
  startSymbols.close();
}

bool symbolTable::validSymbol(string s, int pc, string logFile) {
  ofstream log(logFile, ios_base::app);
  auto valid = true;
  char c;
  c = s.at(0);
  if (s.length() > 32) { /* invalid if longer than 32 characters */
    log << "label '" << s << "' is longer than 32 charecters at PC " << pc << endl;
    return false;
  }
  if (!isalpha(c) && c != '_') { /* invalid if first charecter is not a alphabet or underscore */
    log << "label '" << s << "' has invalid first character at PC " << pc << endl;
    return false;
  }
  for (auto i = 1; i < s.length(); i++) { /* invalid if other are not alphanumeric or underscore */
    c = s.at(i);
    if (!isalnum(c) && c != '_') {
      log << "label '" << s << "' has invalid characters at PC " << pc << endl;
      return false;
    }
  }
  log.close();
  return valid;
}

void symbolTable::printTable() {
  for (auto i = symbolList.begin(); i != symbolList.end(); ++i)
    i->print();
}