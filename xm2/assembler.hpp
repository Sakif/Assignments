#pragma once
#include "all.hpp"

using namespace std;

#ifndef ASSEMBLER
#define ASSEMBLER

vector<string> tokenize(string, bool = true, string = "\\s+");

void assembler(string);

void endAssembler();

string currentTime();

#endif
