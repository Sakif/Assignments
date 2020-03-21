#include "all.hpp"

ifstream asmFile;
ofstream lisFile;
unsigned lineNumber;
short programCounter;
unsigned errorCount;

void assembler(string file) {
  auto extention = file.substr(file.find_last_of('.'));
  if (extention == ".asm") {
    auto outFile = file.substr(0, file.find_last_of('.'));
    outFile.append(".lis");
    lisFile.open(outFile);
  } else
    cout << err << "Please enter a file .asm file." << endl;
}

void endAssembler() {
  lisFile.close();
  asmFile.close();
}
