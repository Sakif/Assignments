#include "Assembler.hpp"
#include <regex>

using namespace std;

Assembler::Assembler(string asmFileName) {
  if (asmFileName.substr(asmFileName.find_first_of(".")) == ".asm") {
    asmFile.open(asmFileName);
    if (asmFile.is_open()) {
      auto lisFileName = asmFileName.substr(0, asmFileName.find_first_of(".")) + ".lis";
      lisFile.open(lisFileName);
    } else
      cout << "The file: " << asmFileName << " could not be opened or does not exist." << endl;
  } else
    cout << "Please provide an assembly file" << endl;
}

Assembler::~Assembler() {
  asmFile.close();
  lisFile.close();
}

list<string> Assembler::tokenize(string line, bool removeComment, string delim) {
  if (removeComment)
    line = line.substr(0, line.find_first_of(";"));
  regex rx(delim);
  list<string> tokens;
  sregex_token_iterator itr(line.begin(), line.end(), rx, -1);
  sregex_token_iterator end;
  while (itr != end) {
    if (itr->length() > 0)
      tokens.push_back(*itr);
    itr++;
  }
  return tokens;
}