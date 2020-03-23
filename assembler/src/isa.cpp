#include "isa.hpp"

instruction findISA(string n) {
  /* default */
  instruction ins = {"", -10, true, NO_OP};

  /* change all character of n to uppercase */
  for_each(n.begin(), n.end(), [](char& c) { c = ::toupper(c); });

  /* search the ISA table to see if n exist,
   * if it is does then return the ISA */
  for (auto i = 0U; i < isaTable.size(); i++)
    if (isaTable[i].name == n) return isaTable[i];
  return ins;
}

int operandToInt(string op) {
  auto value = 0;
  auto firstChar = op[0];
  op.erase(0, 1);
  if (firstChar == '#')
    value = stoi(op);
  else if (firstChar == '$')
    value = stoi(op, 0, 16);
  else if (firstChar == '\\')
    value = op[0];
  return value;
}

void directoryProcess(string n, string op, int& pc, symbolTable& stable, ostream& out) {
  auto intHolder = 0;
  if (n == "ORG") {
    intHolder = operandToInt(op);
    if (intHolder < MAX_NUMBER_LENGTH)
      pc = intHolder;
    else
      out << err << endl;
  } else if (n == "EQU") {
    stable.find(op);
  } else
    out << err << endl;
}
