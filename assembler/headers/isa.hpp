#pragma once
#include "definitions.hpp"

using namespace std;

#ifndef INSTRUCTION
#define INSTRUCTION

struct instruction {
  string name;
  int pcIncrement;
  bool directory;
};

const vector<instruction> isaTable = {
    {"ADD", 2, false},
    {"BNE", 2, false},
    {"CMP", 2, false},
    {"END", 2, false},
    {"LD", 2, false},
    {"MOVLS", 2, false},
    {"MOVLZ", 2, false},
    {"ORG", 0, true},
    {"ST", 2, false},
    {"WORD", 0, true}};

instruction findISA(string);

#endif
