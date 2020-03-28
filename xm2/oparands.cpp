#include "all.hpp"

using namespace std;

extern ifstream asmFile;
extern ofstream lisFile;
extern unsigned lineNumber;
extern short programCounter;
extern unsigned errorCount;
extern vector<string> tokens;
extern SymbolTable symbolTable;

void processOperands() {
  /* operands are at the end of */
  auto end = tokens.size() - 1;
  auto opToken = tokens.at(end);
  auto ops = tokenize(opToken, false, ",");
  lisFile << "Ops: ";
  for (auto o : ops) lisFile << o << "\t";
  lisFile << endl;
}
