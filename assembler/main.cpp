#include "main.hpp"

using namespace std;

void testTokens(string l) {
  cout << "In: " << l << endl;
  auto tokens = Assembler::tokenize(l);
  cout << "Length: " << tokens.size() << endl;
  for (auto t : tokens)
    cout << t << endl;
}

int main(int const argc, char const *argv[]) {
  if (argc < 2)
    cout << "Please pass a file." << endl;
  else
    Assembler a(argv[1]);
  testTokens("s");
  testTokens("    ld	R0,#1	");
  testTokens("ldr R5,#-60,r0");
  testTokens("	SIZE equ $26");
  testTokens("CAP_A equ 'A'");
  testTokens("  org #80");

  return 0;
}
