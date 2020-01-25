#pragma once
#include <sstream>
#include <string>

using namespace std;

#ifndef ERROR
#define ERROR

enum error {
  NO_ERROR,
  UNEXPECTED_TOKEN,
  INVALID_LABLE
};

const string err = "\u274C\t";

const string errorString[] = {
    "No Error",
    "Encountered unexpected token",
    "Invalid label. Labels must be less than 32 characters, first character being _ or albhabetic, and other characters being _ or alphanumeric."};

#endif
