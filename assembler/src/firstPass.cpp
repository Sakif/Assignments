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
  if (inst.pcIncrement < 0) return false;

  programCounter += inst.pcIncrement;
  return true;
}

void assembler::lineProcessingFirstPass(vector<string> tokens) {
  auto tokenCount = 0U;
  if (tokens.size() < 1) return;
  auto is1stInstruction = isaProcess(tokens[tokenCount]);
  if (!is1stInstruction) {
    auto validLabel = sTable.validLabel(tokens[tokenCount]);
    if (!validLabel)
      lisFile << err << errorString[INVALID_LABEL] << endl;
    else {
      auto label = sTable.find(tokens[tokenCount]);
      if (label.value < 0) sTable.addSymbol(tokens[tokenCount], LABEL, programCounter);
      if (++tokenCount < tokens.size()) {
        auto is2ndInstruction = isaProcess(tokens[tokenCount]);
        if (!is2ndInstruction) {
          lisFile << err << errorString[NOT_INSTRUCTION] << endl;
          return;
        }
      } else {
        return;
      }
    }
  }
}
