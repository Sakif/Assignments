#include <cmath>
#include <iostream>

using namespace std;

void primeFactors(int n) {
  cout << "Factors: ";
  while (n % 2 == 0) {
    cout << 2 << " ";
    n = n / 2;
  }
  for (auto i = 3U; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      cout << i << " ";
      n /= i;
    }
  }
  if (n > 2)
    cout << n << " ";
  cout << endl;
}

int main() {
  auto n = 5;
  primeFactors(n);
  n = 8;
  primeFactors(n);
  n = 20;
  primeFactors(n);
  return 0;
}
