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
  //symbolTable sTable;

  string formatLine(string) const;
  string formatLine(vector<string>) const;
  vector<string> tokenize(string, bool = true, string = "\\s+");

public:
  assembler(string);
  ~assembler();

  bool firstPass();
  bool secondPass();
};

#endif
