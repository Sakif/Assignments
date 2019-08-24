#pragma once
#include <string>

#ifndef SYMBOL_TYPE
#define SYMBOL_TYPE

enum SymbolType {
  UNKNOWN,
  LABEL,
  REGISTER
};

const std::string symbolTypeToString[] = {
    "UNKNOWN",
    "LABEL",
    "REGISTER"};

#endif

#ifndef SYMBOL_CONSTANTS
#define SYMBOL_CONSTANTS
const auto maxSymbolLength = 32U;
const auto maxTypeLength = symbolTypeToString[REGISTER].length();
#endif

#ifndef ERROR_TYPES
#define ERROR_TYPES

enum error_type {
  NO_ERROR,
  LABEL_TOO_LONG,
  INVALID_FIRST_CHARACTER,
  INVALID_CHARACTER
};

#define INVALID_FIRST_CHAR(ch) (!isalpha(ch) && !(ch == '_'))
#define INVALID_CHAR(ch) (!isalnum(ch) && !(ch == '_'))

const std::string errorToString[] = {
    "No error",
    "The length of the label is greater than maximum allowed length",
    "Label must start with _ or alphabetic character",
    "Label can only contain _ or other alphanumeric character"};
#endif