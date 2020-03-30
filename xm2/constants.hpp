/*
Author: Sakif Fahmid Zaman
*/

#pragma once
#include "all.hpp"

#ifndef CONSTANTS_H
#define CONSTANTS_H

const string err = "\u274C\t";

#define MAX_LABEL_LENGTH 32

#define ALPHABETIC(x) ((x == '_') || ('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z'))

#define ALPHANUMERIC(x) (ALPHABETIC(x) || ('0' <= x && x <= '9'))

enum SymbolType { UNKNOWN,
                  LABEL,
                  REGISTER };

const string SymbolTypeToString[] = {"UNKNOWN", "LABEL", "REGISTER"};

#endif
