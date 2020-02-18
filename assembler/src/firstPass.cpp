#include "assembler.hpp"

using namespace std;

int token2int(string s) {
  int v = 0;
  auto firstChar = s[0];
  s.erase(s.begin());
  if (firstChar == '#')
    v = stoi(s);
  else if (firstChar == '$')
    v = stoi(s, nullptr, 16);
  else
    throw 0;
  return v;
}

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
      lineProcessingFirstPass();
  }
  sTable.printTable(lisFile);
  return passed;
}

vector<int> assembler::processOperands(string tok) {
  vector<int> out;
  string token;
  stringstream l(tok);
  while (getline(l, token, ',')) {
    lisFile << token[0] << endl;
    out.push_back(token2int(token));
  }
  return out;
}

bool assembler::isaProcess() {
  auto inst = findISA(tokens[tokenCount]);
  if (inst.pcIncrement < 0) return false;
  programCounter += inst.pcIncrement;
  if (inst.op != NO_OP || inst.op != OPTIONAL) {
    tokenCount++;
    auto ops = processOperands(tokens[tokenCount]);
  }

  return true;
}

void assembler::lineProcessingFirstPass() {
  tokenCount = 0U;
  if (tokens.size() < 1) return;
  auto is1stInstruction = isaProcess();
  if (!is1stInstruction) {
    auto validLabel = sTable.validLabel(tokens[tokenCount]);
    if (!validLabel)
      lisFile << err << errorString[INVALID_LABEL] << endl;
    else {
      auto label = sTable.find(tokens[tokenCount]);
      if (label.value < 0) sTable.addSymbol(tokens[tokenCount], LABEL, programCounter);
      if (++tokenCount < tokens.size()) {
        auto is2ndInstruction = isaProcess();
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
