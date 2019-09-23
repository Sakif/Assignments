#include <climits>
#include <iostream>

using namespace std;

unsigned nthPrime(unsigned n) {
  auto prime = 0U, check = 0U, c = 0U;
  for (auto i = 2U; i <= USHRT_MAX; i++) {
    check = 0;
    for (auto j = 2U; j <= i / 2; j++) {
      if (i % j == 0) {
        check = 1;
        break;
      }
    }
    if (check == 0)
      c++;
    if (c == n) {
      prime = i;
      break;
    }
  }
  return prime;
}

int main() {
  auto n = 0U;
  cout << "Enter Prime Number you want to Find: ";
  cin >> n;
  auto prime = nthPrime(n);
  if (n < 1)
    cout << "There are no prime number less than 1." << endl;
  else
    cout << n << " prime number is " << prime << endl;
  return 0;
}
