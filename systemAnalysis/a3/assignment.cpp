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
  if (!validMQP(parameterM)) throw 22;
  inFile >> parameterQ;
  if (!validMQP(parameterQ)) throw 22;
  inFile >> parameterP;
  if (!validMQP(parameterP)) throw 22;

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

  return validCount > 6;
}

void assignment::test() {
  /* outFile << "Parameter L: " << parameterL << endl;
  outFile << "Parameter I: " << parameterI << endl;
  outFile << "Parameter N: " << parameterN << endl;
  outFile << "Parameter M: " << parameterM << endl;
  outFile << "Parameter Q: " << parameterQ << endl;
  outFile << "Parameter P: " << parameterP << endl;

  outFile << "n: " << packetSendTime.size() << endl;
  for (auto i : packetSendTime) outFile << i << endl; //*/
}
