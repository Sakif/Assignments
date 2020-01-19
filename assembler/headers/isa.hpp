#pragma once
#include "definitions.hpp"

using namespace std;

#ifndef INSTRUCTION
#define INSTRUCTION

struct instruction {
  string name;
  unsigned pcIncrement;
};

const vector<instruction> isaTable = {{"ADD", 2}, {"BNE", 2}, {"CMP", 2}, {"END", 2}, {"LD", 2}, {"MOVLS", 2}, {"MOVLZ", 2}, {"org", 0}, {"ST", 2}, {"word", 0}};

instruction findISA(string);

#endif
