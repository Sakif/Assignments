#pragma once
#include "splitString.hpp"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#define MAX_LABEL_LENGTH 32

using namespace std;

enum symbolType { UNKNOWN,
                  REGISTER,
                  LABEL };

class symbolTable {
private:
  string logfileName;

public:
  class symbol {
  public:
    string name;
    short value;
    symbolType type;

    symbol(string, short, symbolType);
    void print();
    void update(short, symbolType);
  };

  list<symbol> symbolList;

  symbolTable(string = "firstPass.log");

  bool validSymbol(string, int);
  symbol findSymbol(string);
  void addSymbol(string, short, symbolType);
  void printTable();
};

void symbolTable::symbol::update(short pv, symbolType t) {
  value = pv;
  type = t;
}

void symbolTable::addSymbol(string l, short pc, symbolType t) {
  symbol s(l, pc, t);
  symbolList.push_back(s);
}

symbolTable::symbol::symbol(string n, short v, symbolType t) {
  name = n;
  value = v;
  type = t;
}

void symbolTable::symbol::print() {
  ofstream csv("symbol.csv", ios_base::app);
  csv << name << "," << value << "," << type << endl;
  csv.close();
}

symbolTable::symbolTable(string logName) {
  /* This sets up the symbol table so it contains the values of the registers and stack pointer.
   * Those values should be in a file called StartSymbols.csv.
   * Sets up the location of the logfile defaulting to assembler.log
   */
  logfileName = logName;
  ifstream startSymbols("StartSymbols.csv");
  string name = "", line = "";
  auto value = 0;
  symbolType type = UNKNOWN;
  auto s = new symbol(name, value, type);
  while (getline(startSymbols, line)) {
    auto tokens = splitString(line, ",");
    name = tokens.front();
    tokens.pop_front();
    value = stoi(tokens.front());
    tokens.pop_front();
    type = static_cast<symbolType>(stoi(tokens.front()));
    s = new symbol(name, value, type);
    symbolList.push_back(*s);
  }
  startSymbols.close();
}

bool symbolTable::validSymbol(string s, int pc) {
  ofstream log(logfileName, ios_base::app);
  auto valid = true;
  char c = s.at(0);                    /* the first charecter */
  if (s.length() > MAX_LABEL_LENGTH) { /* invalid if longer than the maximum label length characters */
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

symbolTable::symbol symbolTable::findSymbol(string label) {
  for (auto n : symbolList) {
    if (n.name == label)
      return n;
  }
  return symbol("", -1, UNKNOWN);
}

void symbolTable::printTable() {
  for (auto i = symbolList.begin(); i != symbolList.end(); ++i)
    i->print();
}