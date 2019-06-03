#pragma once
#include "splitString.hpp"
#include "symbol.hpp"
#include <cctype>
#include <fstream>
#include <iostream>

#define MAX_LABEL_LENGTH 32

using namespace std;

class symbolTable {
private:
  string logfileName;
  symbol *start;
  unsigned int count;
  void pop(); /* needed for distructor */

public:
  symbolTable(string = "firstPass.log");
  ~symbolTable();

  bool validSymbol(string, int) const;
  symbol *findSymbol(string) const;
  void addSymbol(string, short = 0, symbolType = UNKNOWN);
  void printTable(string = "symbols.csv") const;
  unsigned int symbolCount() const;
};

symbolTable::symbolTable(string logName) : logfileName(logName), count(0) {
  /* This sets up the symbol table so it contains the values of the registers and stack pointer.
   * Those values should be in a file called StartSymbols.csv.
   * Sets up the location of the logfile defaulting to assembler.log
   */
  start = nullptr;

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
    addSymbol(name, value, type);
  }
  startSymbols.close();
}

void symbolTable::pop() {
  auto temp = start;
  start = temp->next;
  count--;
  delete temp;
}

symbolTable::~symbolTable() {
  while (start != nullptr)
    pop();
}

bool symbolTable::validSymbol(string s, int pc) const {
  ofstream log(logfileName, ios_base::app);
  auto valid = true; /* the default condition */
  char c = s.at(0);  /* the first charecter */

  if (s.length() > MAX_LABEL_LENGTH) { /* invalid if longer than the maximum label length characters */
    log << "label '" << s << "' is longer than 32 charecters at PC " << pc << endl;
    return false;
  }

  if (!isalpha(c) && c != '_') { /* invalid if first charecter is not a alphabet and not underscore */
    log << "label '" << s << "' has invalid first character at PC " << pc << endl;
    return false;
  }

  for (auto i = 1; i < s.length(); i++) { /* invalid if other are not alphanumeric and not underscore */
    c = s.at(i);
    if (!isalnum(c) && c != '_') {
      log << "label '" << s << "' has invalid characters at PC " << pc << endl;
      return false;
    }
  }

  log.close();
  return valid;
}

void symbolTable::addSymbol(string name, short value, symbolType type) {
  auto s = new symbol(name, value, type, start);
  start = s;
  count++;
}

symbol *symbolTable::findSymbol(string label) const {
  auto node = start;
  while (node != nullptr) {
    if (node->name == label)
      return node;
    else
      node = node->next;
  }
  return node;
}

void symbolTable::printTable(string out) const {
  ofstream o(out, ios_base::app);
  for (auto n = start; n != nullptr; n = n->next)
    o << n->name << "," << n->value << "," << n->type << endl;
  o.close();
}

unsigned int symbolTable::symbolCount() const {
  return count;
}