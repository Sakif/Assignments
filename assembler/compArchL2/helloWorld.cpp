#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  cout << "You have entered " << argc << " arguments:"
       << "\n";

  for (int i = 0; i < argc; ++i)
    cout << argv[i] << "\n";

  cout << "XOR checksum test" << endl;
  int sum = '4';
  sum = sum ^ 'A';
  cout << "sum: " << sum << endl;
  sum = sum ^ 'B';
  cout << "sum: " << sum << endl;
  sum = sum ^ '1';
  cout << "sum: " << sum << endl;
  return 0;
}