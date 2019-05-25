#include "sortTokens.hpp"
#include "splitString.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream readFile(argv[1]);
  ofstream writeFile("log.txt", ofstream::out);

  if (!readFile) { /* if file does not exist */
    cout << "Could not read file." << endl;
    return 1;
  }

  string line;
  auto comaCount = 0.0;
  auto sheCount = 0U;

  while (getline(readFile, line)) {
    auto tokens = resplit(line);
    while (!tokens.empty()) {
      auto tkn = tokens.front();              /* get the first token */
      auto comaFound = tkn.find(",");         /* search for coma in the token */
      comaCount += comaFound != string::npos; /* if not npos means there is a coma in token */

      auto sheFount = tkn.find("she"); /* compares tokens to see if it contains she and She because they are case sensetive */
      sheCount += sheFount != string::npos;
      sheFount = tkn.find("She");
      sheCount += sheFount != string::npos;

      writeFile << tkn << "\t" << tkn.length() << endl; /* add the token to log file along with its length */
      tokens.pop_front();                               /* remove the token from list */
    }
  }

  printf("Coma found: %f\n", comaCount);
  printf("she+She found: 0x%x\n", sheCount);
  auto sortMe = sortedTokens("SortMe.txt").front(); /* should return Lorem a L is 76 where as the other characters have higher values */
  cout << "First token to sort: " << sortMe << endl;
  readFile.close();
  writeFile.close();
  return 0;
}