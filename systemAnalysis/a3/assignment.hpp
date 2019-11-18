#pragma once
#include "start.hpp"

using namespace std;

#ifndef ASSIGNMENT
#define ASSIGNMENT

class assignment {
private:
  ifstream inFile;
  ofstream outFile;

public:
  assignment(string = "input.txt", string = "output.txt");
  ~assignment();
};

#endif
