#pragma once
#include "definitions.hpp"

using namespace std;

#ifndef ERROR
#define ERROR

enum error {
  NO_ERROR,
  UNEXPECTED_TOKEN,
  INVALID_LABEL,
  NOT_INSTRUCTION,
  NO_OP_FOUND
};

const string err = "\u274C\t";

const string errorString[] = {
    "No Error.",
    "Encountered unexpected token.",
    "Invalid label. Labels must be less than 32 characters, first character being _ or alphabetic, and other characters being _ or alphanumeric.",
    "Not an instruction nor directory.",
    "The instruction/directory requires operands. None were found."};

#endif
