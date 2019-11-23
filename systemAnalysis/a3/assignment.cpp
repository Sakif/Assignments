/*
Author: Sakif Fahmid Zaman
ID: B00756635
*/

#include "assignment.hpp"

using namespace std;

bool validLIN(int param) {
  if (param > 0 && param < 101) return true;
  return false;
}

bool validMQP(int param) {
  if (param > 0 && param < 11) return true;
  return false;
}

assignment::assignment(string inFileName, string outFileName) {
  inFile.open(inFileName);
  outFile.open(outFileName);

  inFile >> parameterL;
  inFile >> parameterI;
  inFile >> parameterN;

  inFile >> parameterM;
  inFile >> parameterQ;
  inFile >> parameterP;

  auto s = 0;
  inFile >> packetCount;
  for (auto i = 0; i < packetCount; i++) {
    inFile >> s;
    packetSendTime.push_back(s);
  }
}

assignment::~assignment() {
  inFile.close();
  outFile.close();
  while (!packetSendTime.empty()) packetSendTime.pop_back();
}

bool assignment::validParam() const {
  auto validCount = 0;
  validCount += validLIN(parameterL);
  clog << "Valid L " << validLIN(parameterL) << endl;

  validCount += validLIN(parameterI);
  clog << "Valid I " << validLIN(parameterI) << endl;

  validCount += validLIN(parameterN);
  clog << "Valid N " << validLIN(parameterN) << endl;

  validCount += validMQP(parameterM);
  clog << "Valid M " << validMQP(parameterM) << endl;

  validCount += validMQP(parameterP);
  clog << "Valid P " << validMQP(parameterP) << endl;

  validCount += validMQP(parameterQ);
  clog << "Valid Q " << validMQP(parameterQ) << endl;

  validCount += (packetCount < 1001 && packetCount > 0);
  clog << "Valid n " << (packetCount < 1001 && packetCount > 0) << endl;

  return validCount > 6;
}

/* 
not needed as they are unique
void assignment::sortPackets() { packetSendTime.sort(); }
*/

void assignment::test() {
  /* outFile << "Parameter L: " << parameterL << endl;
  outFile << "Parameter I: " << parameterI << endl;
  outFile << "Parameter N: " << parameterN << endl;
  outFile << "Parameter M: " << parameterM << endl;
  outFile << "Parameter Q: " << parameterQ << endl;
  outFile << "Parameter P: " << parameterP << endl;*/

  outFile << "packetCount: " << packetSendTime.size() << endl;
  for (auto i : packetSendTime) outFile << i << endl;  //*/
}
