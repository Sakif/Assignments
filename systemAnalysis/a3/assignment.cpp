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

char assignment::conflict(int earlyPacket, int latePacket) {
  auto colitionType = 'D';
  if (earlyPacket + parameterL < latePacket)
    colitionType = 'S';
  else if (earlyPacket)
    colitionType = 'a';
  else if (earlyPacket)
    colitionType = 'd';
  return colitionType;
}

char assignment::checkP(list<int>::iterator cp) {
  auto collition = 'S';
  auto pp = cp;
  pp--;
  while (*pp) {
  }
  return collition;
}

char assignment::checkN(list<int>::iterator cp) {
  auto collition = 'S';
  auto np = cp;
  np++;
  while (*np) {
  }
  return collition;
}

void assignment::simulate() {
  for (auto cp = packetSendTime.begin(); cp != packetSendTime.end(); cp++) {
    auto c = checkP(cp);
    if (c != 'S') c = checkN(cp);
    cout << c << endl;
  }
}
