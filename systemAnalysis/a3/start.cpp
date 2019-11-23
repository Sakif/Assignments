#include "assignment.hpp"

using namespace std;

int main(const int argc, const char** argv) {
  if (argc < 1)
    cout << "Please supply the name of the input and output files." << endl;
  else {
    assignment app(argv[1]);
    if (app.validParam()) {
      app.test();
    } else
      cout << "Invalid parameter." << endl;
  }
  return 0;
}
