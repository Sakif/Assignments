#include "splitString.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream readFile(argv[1]);
  ofstream writeFile("log.txt", ofstream::out);

  if (!readFile) { /* if file does not exist */
    cout << "Could not read file." << endl;
    return 1;
  }

  string line;
  double comaCount = 0.0;

  while (getline(readFile, line)) {
    // cout << line << endl;
    auto tokens = resplit(line);
    while (!tokens.empty()) {
      auto tkn = tokens.front();
      auto found = tkn.find(",");
      if (found != string::npos)
        comaCount += 1.0;
      writeFile << tkn << "\t" << tkn.length() << endl;
      tokens.pop_front();
    }
  }

  writeFile << "Coma Count: " << scientific << comaCount << endl;
  readFile.close();
  writeFile.close();
  return 0;
}
