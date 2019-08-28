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

int main(/*int const argc, char const *argv[]*/) {
  testTokens("s");
  testTokens("R0,#1");
  testTokens("R5,#-60,r0");
  testTokens("$26");
  testTokens(" 'A'");
  testTokens("#80");

  return 0;
}
