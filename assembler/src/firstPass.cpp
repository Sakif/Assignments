#include "assembler.hpp"

using namespace std;

bool assembler::firstPass() {
  auto passed = false;
  string line;
  while (getline(asmFile, line)) {
    outFile << formatLine(line) << endl;
    auto tokens = tokenize(line);
    lineNumber++;
    if (tokens.size() > 3)
      outFile << err << errorString[UNEXPECTED_TOKEN] << endl;
    else
      lineProcessingFirstPass(tokens);
  }
  return passed;
}

void assembler::lineProcessingFirstPass(vector<string> tokens) {
  auto tokenCount = 0U;
  if (tokens.size() > 0) {
    auto inst = findISA(tokens.at(0));
    if (inst.name != "") programCounter += inst.pcIncrement;
  }
}