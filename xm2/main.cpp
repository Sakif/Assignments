#include "all.hpp"

int main(int argc, char** argv) {
  if (argc >= 2) {
    if (argc > 2) cout << "!\tCannot compile more than 1 file at a time. Compiling the first file." << endl;
    assembler(argv[1]);
    auto pass1 = firstPass(argv[1]);
    pass1 ? cout << endl : cout << err << "Pass 1 failed" << endl;
    endAssembler();
  } else
    cout << err << "Please specify an assembly file you would like to compile." << endl;
  return 0;
}
