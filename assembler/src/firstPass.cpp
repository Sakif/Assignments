#include "assembler.hpp"

using namespace std;

bool assembler::firstPass() {
  auto passed = false;
  string line;
  while (getline(asmFile, line)) {
    outFile << formatLine(line) << endl;
    auto tokens = tokenize(line, true);
    lineNumber++;
    if (tokens.size() > 3)
      outFile << err << errorString[UNEXPECTED_TOKEN] << endl;
    else {
    }
  }
  return passed;
}
