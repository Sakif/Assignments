#pragma once
#include <sstream>
#include <string>

using namespace std;

#ifndef ERROR
#define ERROR

enum error {
  NO_ERROR,
  UNEXPECTED_TOKEN
};

const string err = "\u274C\t";

const string errorString[] = {
    "No Error",
    "Encountered unexpected token"};

#endif
