#include "symbols.hpp"

using namespace std;

symbolTable::symbolTable() {
  symbol a = {"R7", REGISTER, 7};
  table.push_back(a);
  a = {"R6", REGISTER, 6};
  table.push_back(a);
  a = {"R5", REGISTER, 5};
  table.push_back(a);
  a = {"R4", REGISTER, 4};
  table.push_back(a);
  a = {"R3", REGISTER, 3};
  table.push_back(a);
  a = {"R2", REGISTER, 2};
  table.push_back(a);
  a = {"R1", REGISTER, 1};
  table.push_back(a);
  a = {"R0", REGISTER, 0};
  table.push_back(a);
}

void symbolTable::printTable(ofstream &out) const {
  out << "\nSYMBOL TABLE" << endl;
  for (auto s : table) {
    out << s.label << ", ";
    out << symbolTypeToString[s.type] << ", ";
    out << s.value << endl;
  }
}

bool symbolTable::validLabel(string l) const {
  auto valid = true;
  if (l.length() > MAX_LABEL_LENGTH) valid = false;
  if (INVALID_FIRST_CHAR(l.at(0))) valid = false;
  for (auto c : l)
    if (INVALID_CHAR(c)) valid = false;
  return valid;
}

void symbolTable::addSymbol(string n, SymbolType t, int v) {
  symbol a = {n, t, v};
  table.push_back(a);
}
