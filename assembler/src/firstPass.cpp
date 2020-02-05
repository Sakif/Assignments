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
    auto is1stInstruction = isaProcess(tokens.at(tokenCount));

    if (!is1stInstruction) {
      auto validLabel = sTable.validLabel(tokens.at(tokenCount));
      if (!validLabel)
        lisFile << err << errorString[INVALID_LABEL] << endl;
      else {
        auto label = sTable.find(tokens.at(tokenCount));
        if (label.value < 0) sTable.addSymbol(tokens.at(tokenCount), LABEL, programCounter);
      }
    }

    if (++tokenCount > tokens.size()) {
      auto is2ndInstruction = isaProcess(tokens.at(tokenCount));
      if (!is2ndInstruction) return;
    }
  }
}
