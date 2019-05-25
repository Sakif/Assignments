#include <fstream>
#include <iostream>
#include <list>

using namespace std;

list<string> sortedTokens(string fileName) {
  ifstream file(fileName);
  string line;
  list<string> tokens;
  while (getline(file, line))
    tokens.push_back(line);
  file.close();
  tokens.sort();
  return tokens;
}
