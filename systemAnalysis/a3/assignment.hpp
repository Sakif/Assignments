/*
Author: Sakif Fahmid Zaman
ID: B00756635
*/

#pragma once
#include "start.hpp"

using namespace std;

#ifndef ASSIGNMENT
#define ASSIGNMENT

class assignment {
private:
  ifstream inFile;
  ofstream outFile;
  int parameterL, parameterI, parameterN, parameterM, parameterQ, parameterP, packetCount;
  list<int> packetSendTime;
  char conflict(int, int);

public:
  assignment(string = "input.txt", string = "output.txt");
  ~assignment();
  bool validParam() const;
  void simulate();
  /* void sortPackets(); */
  void test();
};

#endif
