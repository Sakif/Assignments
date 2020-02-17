#include "assembler.hpp"

using namespace std;

assembler::assembler(string file) {
  auto extention = file.substr(file.find_last_of('.'));
  if (extention == ".asm") {
    auto outFile = file.substr(0, file.find_last_of('.'));
    outFile.append(".lis");
    lisFile.open(outFile);
    asmFile.open(file);
    lineNumber = 1;
    programCounter = 0;
  } else
    cout << "\u274C\tNot a .asm file. Cannot compile." << endl;
}

assembler::~assembler() {
  asmFile.close();
  lisFile.close();
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

string assembler::formatLine(string line) const {
  stringstream s;
  s << lineNumber << "\t" << programCounter << "\t" << line;
  return s.str();
}

string assembler::formatLine(vector<string> tokens) const {
  stringstream s;
  s << lineNumber << "\t" << programCounter << "\t";
  for (auto i = 0U; i < tokens.size(); i++)
    s << tokens.at(i) << "\t";
  return s.str();
}

vector<int> assembler::processOperands(string tok) {
  vector<int> out;
  string token;
  stringstream l(tok);
  while (getline(l, token, ',')) {
    lisFile << token[0] << endl;
  }
  return out;
}
