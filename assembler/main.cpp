#include "main.hpp"

using namespace std;

int main() {
  cout << "Hi" << endl;
  SymbolTable table;
  cout << table << endl;

  string lbl = "na";
  auto error = table.validLabel(lbl);
  if (error != NO_ERROR)
    cout << lbl << errorToString[error] << endl;

  lbl = "_na";
  error = table.validLabel("_na");
  if (error != NO_ERROR)
    cout << lbl << errorToString[error] << endl;

  lbl = "6asd";
  error = table.validLabel(lbl);
  if (error != NO_ERROR)
    cout << lbl << errorToString[error] << endl;

  lbl = "_na654";
  error = table.validLabel(lbl);
  if (error != NO_ERROR)
    cout << lbl << errorToString[error] << endl;

  lbl = "_na#";
  error = table.validLabel(lbl);
  if (error != NO_ERROR)
    cout << lbl << errorToString[error] << endl;

  auto n = table.find("R5");
  cout << n->printType() << endl;
  return 0;
}
