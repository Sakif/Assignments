#include "isa.hpp"

instruction findISA(string n) {
  instruction ins = {"", 0};

  for (auto i = 0U; i < isaTable.size(); i++)
    if (isaTable.at(i).name == n) ins = isaTable.at(i);

  return ins;
}
