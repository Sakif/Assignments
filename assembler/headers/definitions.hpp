#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

#ifndef MAX_LABEL_LENGTH
#define MAX_LABEL_LENGTH 32
#endif

#ifndef MAX_NUMBER_LENGTH
#define MAX_NUMBER_LENGTH 65535
#endif

#define INVALID_FIRST_CHAR(ch) (!isalpha(ch) && !(ch == '_'))
#define INVALID_CHAR(ch) (!isalnum(ch) && !(ch == '_'))
