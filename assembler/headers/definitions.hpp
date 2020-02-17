#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#define MAX_LABEL_LENGTH 32
#define MAX_NUMBER_LENGTH 65535

#define INVALID_FIRST_CHAR(ch) (!isalpha(ch) && !(ch == '_'))
#define INVALID_CHAR(ch) (!isalnum(ch) && !(ch == '_'))

int token2int(std::string s);