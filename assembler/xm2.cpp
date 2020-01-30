#include "assembler.hpp"

using namespace std;

int main(int argc, char **argv) {
  if (argc < 2)
    cout << "Specify the assembly file that you wish to compile." << endl;
  else if (argc > 2)
    cout << "Cannot compile more than 1 file." << endl;
  else {
    assembler xm2(argv[1]);
    auto pass1Good = xm2.firstPass();
    auto pass2Good = false;
    if (pass1Good) {
      pass2Good = xm2.secondPass();
      if (!pass2Good)
        cout << err << "Compilation failed on second pass." << endl;
      else
        cout << err << "Compilation compleated." << endl;
    } else
      cout << err << "Compilation failed on first pass." << endl;
  }
  return 0;
}
