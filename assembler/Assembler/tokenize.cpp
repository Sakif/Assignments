#include "Assembler.hpp"
#include <regex>

using namespace std;

string removeComment(string line) {
  auto lineWithoutComment = line.substr(0, line.find_first_of(";"));
  return lineWithoutComment;
}

list<string> Assembler::tokenize(string line) {
  line = removeComment(line);
  regex rx("\\s+");
  list<string> tokens;
  sregex_token_iterator itr(line.begin(), line.end(), rx, -1);
  sregex_token_iterator end;
  while (itr != end) {
    tokens.push_back(*itr);
    itr++;
  }
  return tokens;
}