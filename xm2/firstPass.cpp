#include "all.hpp"

extern ifstream asmFile;
extern ofstream lisFile;
extern unsigned lineNumber;
extern short programCounter;
extern unsigned errorCount;
extern vector<string> tokens;
extern SymbolTable symbolTable;

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

bool processCommands(string cmd) {
  auto commandIndex = checkTable(cmd);
  if (commandIndex == COMMAND_NOT_FOUND)
    return false;
  else {
    auto command = commands[commandIndex];
    if (command.type == DIRECTORY) {
      processDirectory(commandIndex);
    } else {
      lisFile << command.name << endl;
      processOperands();
      programCounter += 2;
    }
    return true;
  }
}

void checkFirstToken() {
  auto firstToken = tokens[0];
  auto isCommand = processCommands(firstToken);
  if (!isCommand) {
    if (validLabel(firstToken)) {
      auto duplicateSymbol = symbolTable.find(firstToken);
      if (duplicateSymbol == nullptr)
        symbolTable.newSymbol(firstToken, LABEL, programCounter);
      else {
        errorCount++;
        lisFile << err << "Symbol already exist: " << firstToken << endl;
      }
    } else {
      errorCount++;
      lisFile << err << "Invalid label" << endl;
    }
  }
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
    if (tokens.size() > 1)
      checkFirstToken();
    if (tokens.size() > 2) {
    }
  }
  lisFile << symbolTable << endl;
  lisFile << "Error count: " << errorCount << endl;
  if (errorCount > 0)
    return false;
  else
    return true;
}
