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

bool assembler::isaProcess(string i) {
  auto inst = findISA(i);
  if (inst.pcIncrement > -1) {
    programCounter += inst.pcIncrement;
    return true;
  } else
    return false;
}

void assembler::lineProcessingFirstPass(vector<string> tokens) {
  auto tokenCount = 0U;
  if (tokens.size() < 1)
    return;
  else {
    auto isInstruction = isaProcess(tokens.at(tokenCount));
    if (isInstruction)
      tokenCount++;
    else {
      auto validLabel = sTable.validLabel(tokens.at(tokenCount));
      if (!validLabel) lisFile << err << errorString[INVALID_LABEL] << endl;
    }
    if (++tokenCount > tokens.size()) {
      return;
    }
  }
}