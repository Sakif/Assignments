#ifndef FIRST_PASS_H
#define FIRST_PASS_H

#pragma once
#include <fstream>
#include <iostream>
#include <string>

class FirstPass {
private:
  std::ifstream asmFile;
  std::ofstream lisFile;

public:
  FirstPass(std::string);
  ~FirstPass();
};

#endif
