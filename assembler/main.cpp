#include "main.hpp"

using namespace std;

void testTokens(string l) {
  cout << "In: " << l << endl;
  auto tokens = Assembler::tokenize(l, false, ",");
  cout << "Out: ";
  for (auto t : tokens)
    cout << t << " ";
  cout << endl;
}

int main(int const argc, char const *argv[]) {
  if (argc < 2)
    cout << "Please provide a file to assemble" << endl;
  else
    Assembler a(argv[1]);
  return 0;
}
