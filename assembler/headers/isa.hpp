#pragma once
#include "definitions.hpp"

using namespace std;

#ifndef INSTRUCTION
#define INSTRUCTION

enum operand {
  NO_OP,
  OPTIONAL,
  CONSTANT,
  ARITHMETIC,
  BRANCH,
  LONG_BRANCH,
  MEMORY,
  OFFSET_MEMORY
};

struct instruction {
  string name;
  int pcIncrement;
  bool directory;
  operand op;
};

const vector<instruction> isaTable = {
    {"ADD", 2, false, ARITHMETIC},
    {"BNE", 2, false, BRANCH},
    {"BRA", 2, false, BRANCH},
    {"CMP", 2, false, ARITHMETIC},
    {"END", 2, false, OPTIONAL},
    {"LD", 2, false, MEMORY},
    {"MOVLS", 2, false, MEMORY},
    {"MOVLZ", 2, false, MEMORY},
    {"ORG", 0, true, CONSTANT},
    {"ST", 2, false, MEMORY},
    {"WORD", 0, true, CONSTANT}};

instruction findISA(string);

#endif
