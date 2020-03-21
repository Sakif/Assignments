#include "all.hpp"

using namespace std;

int main(int argc, char** argv) {
  if (argc >= 2) {
    if (argc > 2) cout << "!\tCannot compile more than 1 file at a time. Compiling the first file." << endl;
    assembler(argv[1]);
    endAssembler();
  } else
    cout << err << "Please specify an assembly file you would like to compile." << endl;
  auto stbl = SymbolTable();
  stbl.newSymbol("r1", UNKNOWN, 51);
  cout << stbl;
  return 0;
}
