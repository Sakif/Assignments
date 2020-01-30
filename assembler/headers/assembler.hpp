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
  // object variables
  ifstream asmFile;
  ofstream lisFile;
  unsigned lineNumber;
  int programCounter;
  symbolTable sTable;

  // helper functions
  string formatLine(string) const;
  string formatLine(vector<string>) const;
  vector<string> tokenize(string, bool = true, string = "\\s+");

  // helper functions for 1st pass
  void lineProcessingFirstPass(vector<string>);

public:
  assembler(string);
  ~assembler();

  bool firstPass();
  bool secondPass();
};

#endif
