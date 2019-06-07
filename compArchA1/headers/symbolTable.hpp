/* see symbolTable.md */
#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#pragma once
#include "splitString.hpp"
#include "symbol.hpp"
#include <cctype>
#include <fstream>
#include <iostream>

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

  symbol *findSymbol(string) const;
  void addSymbol(string, short = 0, symbolType = UNKNOWN);
  void printTable(string = "symbols.csv") const;
  unsigned int symbolCount() const;
};

symbolTable::symbolTable(string logName) : logfileName(logName), count(0) {
  start = nullptr;
  /* add the default registers */
  addSymbol("R0", 0, REGISTER);
  addSymbol("R1", 1, REGISTER);
  addSymbol("R2", 2, REGISTER);
  addSymbol("R3", 3, REGISTER);
  addSymbol("R4", 4, REGISTER);
  addSymbol("R5", 5, REGISTER);
  addSymbol("LR", 5, REGISTER);
  addSymbol("R6", 6, REGISTER);
  addSymbol("SP", 6, REGISTER);
  addSymbol("R7", 7, REGISTER);
  addSymbol("PC", 7, REGISTER);
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

unsigned int symbolTable::symbolCount() const { return count; }

#endif
