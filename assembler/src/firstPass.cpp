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
  auto inst = findISA(n);
  if (inst.pcIncrement > -1) {
    programCounter += inst.pcIncremnt;
    return true;
  }
  return false;
}

void assembler::lineProcessingFirstPass(vector<string> tokens) {
  auto tokenCount = 0U;
  if (tokens.size() < 1)
    return;
  else {
    /*   auto inst = findISA(tokens.at(tokenCount));
    if (inst.pcIncrement > -1) {
      programCounter += inst.pcIncrement;
      tokenCount++;
    }*/
    else {
      auto validLabel = sTable.validLabel(tokens.at(tokenCount));
      if (!validLabel) lisFile << err << errorString[INVALID_LABLE] << endl;
    }
    if (++tokenCount > tokens.size()) {
      return;
    }
  }
}
