#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<string> opTok = {"$80", "#0", "$FF00", "#1", "Label01,R0", "#16,R2", "\'"};

int processOp(string op) {
  auto value = 0;
  if (op[0] == '#') {
    op.erase(0, 1);
    value = stoi(op);
  } else if (op[0] == '$') {
    op.erase(0, 1);
    value = stoi(op, 0, 16);
  } else if (op[0] == '\\') {
    cout << "escape" << endl;
  } else
    cout << "nope" << endl;
  return value;
}

int main() {
  for (auto ops : opTok)
    cout << processOp(ops) << endl;
  return 0;
}
