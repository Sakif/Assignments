#include "start.hpp"

using namespace std;

int main(const int argc, const char** argv) {
  cout << "Have " << argc << " arguments. They are:" << endl;
  for (auto i = 1; i < argc; i++) cout << argv[i] << endl;
  return 0;
}
