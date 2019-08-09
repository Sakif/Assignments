#include "FirstPass.hpp"

using namespace std;

FirstPass::FirstPass(string assemblyFile) {
  asmFile.open(assemblyFile);
}

FirstPass::~FirstPass() {
  asmFile.clear();
  lisFile.clear();
}
