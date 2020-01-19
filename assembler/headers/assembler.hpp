#pragma once
#include "definitions.hpp"
#include "error.hpp"
#include "isa.hpp"
#include "symbols.hpp"

#ifndef ASSEMBLER
#define ASSEMBLER

using namespace std;

class assembler {
private:
  ifstream asmFile;
  ofstream outFile;
  unsigned lineNumber;
  int programCounter;
  symbolTable sTable;

  string formatLine(string line) const;
  string formatLine(list<string> tokens) const;
  vector<string> tokenize(string line, bool removeComment = false, string dlim = "\\s+");

public:
  assembler(string file);
  ~assembler();

  bool firstPass();
  bool secondPass();
};

#endif
