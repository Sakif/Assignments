#include "formula.hpp"

using namespace std;

#ifndef VARIABLE
#define VARIABLE

class variable : public formula {
public:
  variable(char, int);
  variable();
};

variable::variable(char variableCharecter, int variableValue) {
  value = variableValue;
  formulaString = variableCharecter;
  op1 = nullptr;
  op2 = nullptr;
  find = -1;
}

variable::variable() {
  value = 0;
  op1 = nullptr;
  op2 = nullptr;
  formulaString = "";
  find = -1;
}

#endif
