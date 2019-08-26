#include "Assembler.hpp"

using namespace std;

Assembler::Assembler(string asmFileName) {
  if (asmFileName.substr(asmFileName.find_first_of(".")) == ".asm") {
    asmFile.open(asmFileName);
    if (asmFile.is_open()) {
      cout << "Starting Pass 1" << endl;
      auto lisFileName = asmFileName.substr(0, asmFileName.find_first_of(".")) + ".lis";
      lisFile.open(lisFileName);
    } else
      cout << "The file: " << asmFileName << " could not be opened or does not exist." << endl;
  } else
    cout << "Please provide an assembly file" << endl;
}

Assembler::~Assembler() {
  asmFile.close();
  lisFile.close();
  /* cout << "Closed files" << endl; //*/
}