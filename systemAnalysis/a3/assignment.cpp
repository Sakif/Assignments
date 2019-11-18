#include "assignment.hpp"

using namespace std;

assignment::assignment(string inFileName, string outFileName) {
  inFile.open(inFileName);
  outFile.open(outFileName);
}

assignment::~assignment() {
  inFile.close();
  outFile.close();
}
