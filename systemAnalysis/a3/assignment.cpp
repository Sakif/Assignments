#include "assignment.hpp"

using namespace std;

assignment::assignment(string inFileName, string outFileName) {
  inFile.open(inFileName);
  outFile.open(outFileName);
  inFile >> parameterL;
  inFile >> parameterI;
  inFile >> parameterN;
  inFile >> parameterM;
  inFile >> parameterQ;
  inFile >> parameterP;

  auto n = 0, s = 0;
  inFile >> n;
  for (auto i = 0; i < n; i++) {
    inFile >> s;
    packetSendTime.push_back(s);
  }
}

assignment::~assignment() {
  inFile.close();
  outFile.close();
  while (!packetSendTime.empty()) packetSendTime.pop_back();
}

void assignment::test() {
  outFile << "Parameter L: " << parameterL << endl;
  outFile << "Parameter I: " << parameterI << endl;
  outFile << "Parameter N: " << parameterN << endl;
  outFile << "Parameter M: " << parameterM << endl;
  outFile << "Parameter Q: " << parameterQ << endl;
  outFile << "Parameter P: " << parameterP << endl;

  outFile << "n: " << packetSendTime.size() << endl;
  for (auto i : packetSendTime) outFile << i << endl;
}
