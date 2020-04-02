#pragma once
#include "all.hpp"

using namespace std;

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

/* enum TokenStates {
  firstToken,
  insDir,
  oparands
}; */

vector<string> tokenize(string const, bool = true, string = "\\s+");

void assembler(string const);

void endAssembler();

string currentTime();

bool firstPass(string const);

#endif
