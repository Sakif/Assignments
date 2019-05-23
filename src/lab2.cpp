#include <fstream>
#include <iostream>
#include <list>
#include <regex>
#include <string>
using namespace std;

list<string> resplit(const string &str, string re = "\\s+") {
  list<string> tokens;
  regex rgx(re);

  sregex_token_iterator iter(str.begin(), str.end(), rgx, -1);
  sregex_token_iterator end;
  while (iter != end) {
    tokens.push_back(*iter);
    iter++;
  }
  return tokens;
}

int main(int argc, char *argv[]) {
  ifstream readFile(argv[1]);
  ofstream writeFile("log.txt", ofstream::out);
  if (!readFile) {
    cout << "Could not read file." << endl;
    return 1;
  }

  string line;
  while (getline(readFile, line)) {
    // cout << line << endl;
    auto tokens = resplit(line);
    while (!tokens.empty()) {
      auto tkn = tokens.front();
      writeFile << tkn << "\t" << tkn.length() << endl;
      tokens.pop_front();
    }
  }

  readFile.close();
  writeFile.close();
  return 0;
}