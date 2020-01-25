#include "assembler.hpp"

using namespace std;

bool assembler::firstPass() {
  auto passed = false;
  string line;
  while (getline(asmFile, line)) {
    lisFile << formatLine(line) << endl;
    auto tokens = tokenize(line);
    lineNumber++;
    if (tokens.size() > 3)
      lisFile << err << errorString[UNEXPECTED_TOKEN] << endl;
    else
      lineProcessingFirstPass(tokens);
  }
  sTable.printTable(lisFile);
  return passed;
}

void assembler::lineProcessingFirstPass(vector<string> tokens) {
  auto tokenCount = 0U;
  if (tokens.size() < 1) return;
  auto inst = findISA(tokens.at(tokenCount));
  if (inst.name != "") {
    programCounter += inst.pcIncrement;
    lisFile << "Instruction found: " << inst.name << endl;
  } else {
    auto validLabel = sTable.validLabel(tokens.at(tokenCount));
    if (!validLabel) lisFile << err << errorString[INVALID_LABLE] << endl;
  }
}
