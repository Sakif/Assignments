#include "assembler.hpp"

using namespace std;

assembler::assembler(string file) {
  auto extention = file.substr(file.find_last_of('.'));
  if (extention == ".asm") {
    auto lisFile = file.substr(0, file.find_last_of('.'));
    lisFile.append(".lis");
    outFile.open(lisFile);
    asmFile.open(file);
    lineNumber = 1;
    programCounter = 0;
  } else
    cout << "\u274C\tNot a .asm file. Cannot compile." << endl;
}

assembler::~assembler() {
  asmFile.close();
  outFile.close();
}

vector<string> assembler::tokenize(string line, bool removeComment, string dlim) {
  vector<string> tokens;
  /* removes comments from the line */
  if (removeComment) line = line.substr(0, line.find_first_of(";"));
  /* uses regular expression to tokenize */
  regex rx(dlim);
  sregex_token_iterator itr(line.begin(), line.end(), rx, -1);
  sregex_token_iterator end;
  while (itr != end) {
    if (itr->length() > 0) tokens.push_back(*itr);
    itr++;
  }
  tokens.resize(tokens.size());
  return tokens;
}
