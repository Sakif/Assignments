#pragma once
#include <string>

using namespace std;

class verifyOperands {
private:
  string logFileName;

public:
  verifyOperands(string = "firstPass.log");
  bool constants(string, int);
  bool reg(string, int);
  bool label(string, int);
};

bool validConstant(string token, int pc) {
  bool valid = false;
  return valid;
}

bool validRegister(string token, int pc) {
  bool valid = false;
  return valid;
}

bool validLabel(string token, int pc) {
  bool valid = false;
  return valid;
}
