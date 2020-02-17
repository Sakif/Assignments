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
