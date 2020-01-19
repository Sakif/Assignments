#include <iostream>
#include <string>

using namespace std;

int main() {
  string tname = "testfile.sm";
  auto filename = tname.substr(0, tname.find_last_of('.'));
  cout << filename << endl;
  return 0;
}
