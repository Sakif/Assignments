#include "all.hpp"

void createHeader(string fileName) {
  if (lisFile.is_open()) {
    lisFile << "XM2 assembler" << endl;
    lisFile << "Compiled file: " << fileName << endl;
    lisFile << "Compiled at: " << currentTime() << endl;
  }
}

void printLine(unsigned ln, short pc, string line) {
  /* print line number */
  lisFile << ln << setw(8);
  /* print the program counter as both decimal and hex */
  lisFile << pc << hex << " (0x" << setw(4) << setfill('0') << pc << ")";
  /* print the actual line */
  lisFile << setfill(' ') << dec << "\t" << line << endl;
}

void printTokens() {
  /* good for debugging */
  lisFile << "Tokens: ";
  for (auto tok : tokens) lisFile << tok << "\t";
  lisFile << endl;
}

vector<string> tokenize(string line, bool removeComment, string delim) {
  vector<string> tokens;
  if (removeComment) line = line.substr(0, line.find_first_of(";"));
  regex rx(delim);
  sregex_token_iterator itr(line.begin(), line.end(), rx, -1);
  sregex_token_iterator end;
  while (itr != end) {
    if (itr->length() > 0) tokens.push_back(*itr);
    itr++;
  }
  tokens.resize(tokens.size());
  return tokens;
}

bool firstPass(string fileName) {
  lineNumber = 1;
  createHeader(fileName);
  for (string line; getline(asmFile, line); lineNumber++) {
    printLine(lineNumber, programCounter, line);
    tokens = tokenize(line);
    if (tokens.size() > 3) {
      errorCount++;
      lisFile << err << "Encountered unexpected token" << endl;
    }
    auto firstTokenLabel = checkFirstToken();
    if (firstTokenLabel)
      checkSecondToken();
  }
  lisFile << symbolTable << endl;
  lisFile << "Error count: " << errorCount << endl;
  if (errorCount > 0)
    return false;
  else
    return true;
}
