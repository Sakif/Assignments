#include "all.hpp"

void processOperands(int commandIndex) {
  /* operands are at the end of */
  auto command = commands[commandIndex];
  unsigned long count = command.opCount;
  auto end = tokens.size() - 1;
  auto opToken = tokens.at(end);
  /* tokenize on , */
  auto ops = tokenize(opToken, false, ",");
  if (ops.size() != count)
    lisFile << err << "Invalid number of ops." << endl;
}

bool numeric(string op) {
  auto num = false;
  auto firstChar = op[0];
  if (firstChar == '#') {
    lisFile << "# number" << endl;
    num = true;
  } else if (firstChar == '$') {
    lisFile << "$ number" << endl;
    num = true;
  } else if (firstChar == '\'') {
    lisFile << "space" << endl;
  } else if (firstChar == '\\') {
    lisFile << "Escape character" << endl;
  } else {
    lisFile << "Check symbol table" << endl;
  }
  return num;
}

bool validConstant(unsigned short value) {
  unsigned short constants[] = {0, 1, 2, 4, 8, 16, 32, 0xFFFF};
  for (auto c : constants)
    if (value == c) return true;
  return false;
}

int encodeConstants(int value) {
  auto enc = -1;
  switch (value) {
    case 0:
      enc = 0;
      break;
    case 1:
      enc = 1;
      break;
    case 2:
      enc = 2;
      break;
    case 4:
      enc = 3;
      break;
    case 8:
      enc = 4;
      break;
    case 16:
      enc = 5;
      break;
    case 32:
      enc = 6;
      break;
    case -1:
      enc = 7;
      break;
    default:
      break;
  }
  return enc;
}
