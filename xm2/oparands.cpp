#include "all.hpp"

void processOperands(int const commandIndex) {
  /* operands are at the end of */
  unsigned long opCount = commands[commandIndex].opCount;
  auto end = tokens.size() - 1;
  auto opToken = tokens.at(end);
  /* tokenize on , ignore comments as it should be already removed */
  auto ops = tokenize(opToken, false, ",");
  if (ops.size() != opCount) lisFile << err << "Invalid number of ops." << endl;
}

short tokenToShort(string opToken) {
  short num = 0;
  auto firstChar = opToken[0];
  opToken.erase(opToken.begin());
  if (firstChar == '#')
    num = stoi(opToken);
  else if (firstChar == '$')
    num = stoi(opToken, 0, 16);
  return num;
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
  unsigned short const constants[] = {0, 1, 2, 4, 8, 16, 32, 0xFFFF};
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
      enc = -1;
      break;
  }
  return enc;
}
