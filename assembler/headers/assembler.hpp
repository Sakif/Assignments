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
  unsigned tokenCount = 0;
  vector<string> tokens;

  // helper functions
  string formatLine(string) const;
  string formatLine(vector<string>) const;
  vector<string> tokenize(string, bool = true, string = "\\s+");
  vector<int> processOperands(string);

  // helper functions for 1st pass
  void lineProcessingFirstPass();
  bool isaProcess();

public:
  assembler(string);
  ~assembler();

  bool firstPass();
  bool secondPass();
};

#endif
