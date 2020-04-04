#include "all.hpp"

void processCRR(string op1, string op2) {
  auto sym2 = symbolTable.find(op2);
  if (sym2 == nullptr) {
    errorCount++;
    lisFile << err << "Second operand must be register" << endl;
  } else {
    if (sym2->type != REGISTER) {
      errorCount++;
      lisFile << err << "Second operand must be register" << endl;
    }
  }
  if (op1[0] == '#' || op1[0] == '$')
    lisFile << "op1 constant" << endl;
  else {
    auto sym1 = symbolTable.find(op1);
    if (sym1 == nullptr) symbolTable.newSymbol(op1, UNKNOWN, 0);
  }
}

void processRR(string op1, string op2) {
  auto sym1 = symbolTable.find(op1);
  if (sym1 == nullptr) {
    errorCount++;
    lisFile << err << "Second operand must be register" << endl;
  } else {
    if (sym1->type != REGISTER) {
      errorCount++;
      lisFile << err << "Second operand must be register" << endl;
    }
  }

  auto sym2 = symbolTable.find(op2);
  if (sym2 == nullptr) {
    errorCount++;
    lisFile << err << "Second operand must be register" << endl;
  } else {
    if (sym2->type != REGISTER) {
      errorCount++;
      lisFile << err << "Second operand must be register" << endl;
    }
  }
}

void processC(string op) {
  if (op1[0] != '#' && op1[0] != '$') {
    errorCount++;
    lisFile << err << "Expected a constant" << endl;
  }
}

void processOperands(int const commandIndex) {
  /* operands are at the end of */
  unsigned long opCount = commands[commandIndex].opCount;
  auto opType = commands[commandIndex].ops;
  auto end = tokens.size() - 1;
  auto opToken = tokens.at(end);
  /* tokenize on , ignore comments as it should be already removed */
  auto ops = tokenize(opToken, false, ",");
  if (ops.size() != opCount)
    lisFile << err << "Invalid number of ops." << endl;
  else {
    switch (opType) {
      case CR_R:
        processCRR(ops[0], ops[1]);
        break;

      case R_R:
        processRR(ops[0], ops[1]);
        break;

      case C:
        processC(ops[0]);
        break;

      case R:
        break;

      case Opt:
        break;

      case V:
        break;

      case CEXop:
        break;

      case SA:
        break;

      case LDop:
        break;

      case STop:
        break;

      case LDRop:
        break;

      case STRop:
        break;

      case BRAop:
        break;

      case BRA13:
        break;

      case V_R:
        break;

      default:
        cout << "Not default op." << endl;
        break;
    }
  }
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
