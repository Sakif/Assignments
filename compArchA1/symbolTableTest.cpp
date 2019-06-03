#include "symbolTable.hpp"
#define DEBUG

using namespace std;

int main() {
  symbolTable symtab;
  cout << symtab.validSymbol("6t", 1) << endl;
  cout << symtab.validSymbol("_t", 2) << endl;
  cout << symtab.validSymbol("asdjfhuucv;hnk.jewarfbbekjs..fncs", 3) << endl;
  cout << symtab.validSymbol("asdjfhuucv;hnk.jewarfbbekjs..f", 4) << endl;
  cout << symtab.validSymbol("asdjfhuucv_hnk562jarfbbejsQT3f", 4) << endl;
  auto s = symtab.findSymbol("LOOP");
  if (s == nullptr) {
    cout << "not found" << endl;
    symtab.addSymbol("LOOP");
  }
  s = symtab.findSymbol("LOOP");
  cout << s->type << endl;
  s->update(8, LABEL);
  cout << s->type << endl;
  symtab.printTable();
  return 0;
}