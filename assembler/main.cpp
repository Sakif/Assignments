#include "main.hpp"

using namespace std;

void testTokens(string l) {
  cout << "In: " << l << endl;
  auto tokens = Assembler::tokenize(l);
  cout << "Out: ";
  for (auto t : tokens)
    cout << t << " ";
  cout << endl;
}

int main(/*int const argc, char const *argv[]*/) {
  testTokens("s");
  testTokens("    ld	R0,#1	");
  testTokens("ldr R5,#-60,r0 ;cart");
  testTokens("	SIZE equ $26;fish");
  testTokens("CAP_A equ 'A'; dog");
  testTokens("  org #80 ; mouse");

  return 0;
}
