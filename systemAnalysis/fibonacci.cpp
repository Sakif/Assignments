#include <iostream>

using namespace std;

unsigned long fib(unsigned n) {
  if (n < 2)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  auto n = 30U;
  cout << "N = " << n << endl;
  cout << "Fibonacci: ";
  for (auto i = 0U; i < n; i++)
    cout << fib(i) << endl;
  return 0;
}
