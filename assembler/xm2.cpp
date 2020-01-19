#include "assembler.hpp"

using namespace std;

int main(int argc, char **argv) {
  if (argc < 2)
    cout << "Specify the assembly file that you wish to compile." << endl;
  else {
    assembler xm2(argv[1]);
    auto pass1Good = xm2.firstPass();
    auto pass2Good = false;
    if (pass1Good) {
      pass2Good = xm2.secondPass();
      if (!pass2Good)
        cout << "\u274C\tCompilation failed on second pass." << endl;
      else
        cout << "\u2714\tCompilation compleated." << endl;
    } else
      cout << "\u274C\tCompilation failed on first pass." << endl;
  }
  return 0;
}
