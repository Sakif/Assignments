#include "assignment.hpp"

using namespace std;

int main(const int argc, const char** argv) {
  if (argc < 2)
    cout << "Please supply the name of the input and output files." << endl;
  else
    assignment app(argv[1], argv[2]);
  return 0;
}
