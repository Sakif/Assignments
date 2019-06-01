#include "symbolTable.hpp"
#include <iostream>

using namespace std;

int main() {
  symbolTable symtab;
  cout << symtab.validSymbol("6t", 1) << endl;
  cout << symtab.validSymbol("_t", 2) << endl;
  cout << symtab.validSymbol("asdjfhuucv;hnk.jewarfbbekjs..fncs", 3) << endl;
  cout << symtab.validSymbol("asdjfhuucv;hnk.jewarfbbekjs..f", 4) << endl;
  cout << symtab.validSymbol("asdjfhuucv_hnk562jarfbbejsQT3f", 4) << endl;
  symtab.printTable();
  auto s = symtab.findSymbol("LOOP");
  if (s.value < 0) {
    cout << "Symbol not found" << endl
         << "Adding to symbol Table" << endl;
    symtab.addSymbol("LOOP", 5, LABEL);
  }
  s = symtab.findSymbol("LOOP");
  if (s.value < 0) {
    cout << "Symbol not found" << endl
         << "Adding to symbol Table" << endl;
    symtab.addSymbol("LOOP", 5, LABEL);
  } else {
    printf("Name %s, Value %d, Type %d\n", s.name.c_str(), s.value, s.type);
  }

  return 0;
}