#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<string> tokenize(string line, bool removeComment, string dlim) {
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

vector<string> opTok = {"$80", "#0", "$FF00", "#1", "Label01,R0", "Label02,R1", "R0,R0", "R1,R2", "R0,R2", "#16,R2", "R2,R1"};

int processOp(string t) {
  auto value = 0;
  if (t.at(0) == '#')
    cout << "hash" << endl;
  else if (t.at(0) == '$')
    cout << "dollar" << endl;
  else if (t.at(0) == '\\')
    cout << "" << endl;
  return value;
}

int main() {
  for (auto ops : opTok) {
    auto tok = tokenize(ops, false, ",");
    for (auto i : tok) cout << i << endl;
  }
  return 0;
}
