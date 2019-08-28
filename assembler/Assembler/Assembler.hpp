#ifndef ASSEMBLER
#define ASSEMBLER

#pragma once
#include "SymbolTable.hpp"
#include <fstream>
#include <iostream>

using namespace std;

class Assembler {
private:
  ifstream asmFile;
  ofstream lisFile;
  SymbolTable symbol_table;

public:
  Assembler(string fileName);
  ~Assembler();

  static list<string> tokenize(string line, bool removeComment = true, string delim = "\\s+");
  static ErrorType constantToInteger(string, int &);
};

#endif