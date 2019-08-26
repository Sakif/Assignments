#include "main.hpp"

using namespace std;

int main(int const argc, char const *argv[]) {
  if (argc < 2)
    cout << "Please pass a file." << endl;
  else
    Assembler a(argv[1]);
  return 0;
}
