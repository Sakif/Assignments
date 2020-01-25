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
  ofstream lisFile;
  unsigned lineNumber;
  int programCounter;
  symbolTable sTable;

  string formatLine(string) const;
  string formatLine(vector<string>) const;
  vector<string> tokenize(string, bool = true, string = "\\s+");

  void lineProcessingFirstPass(vector<string>);

public:
  assembler(string);
  ~assembler();

  bool firstPass();
  bool secondPass();
};

#endif
