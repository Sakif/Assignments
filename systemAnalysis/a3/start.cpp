#include "assignment.hpp"

using namespace std;

int main(const int argc, const char** argv) {
  if (argc < 1)
    cout << "Please supply the name of the input and output files." << endl;

  assignment app(argv[1]);
  if (app.validParam())
    cout << endl;
  else
    cout << "Invalid parameter." << endl;
  app.test();

  return 0;
}
