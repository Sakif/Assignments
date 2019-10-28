#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int number) {
  if (number == 1) return false;
  for (auto i = 2; i < number; i++)
    if (number % i == 0) return false;
  return true;
}

int main() {
  const auto maxLine = 10000U, B3 = 7U, B4 = 5U;

  /* get numbers from input.txt */
  vector<int> bullshit;
  auto n = 0;
  ifstream file("input.txt");
  for (auto i = 0U; i < maxLine; i++) {
    file >> n;
    bullshit.push_back(n);
  }
  file.close();

  vector<int> filter1;
  for (auto i = 0U; i < bullshit.size(); i++)
    if ((i + 1) % B3 == 0) filter1.push_back(bullshit.at(i));

  vector<int> filter2;
  for (auto i = 0U; i < filter1.size(); i++) {
    auto n = filter1.at(i);
    if (isPrime(n)) filter2.push_back(n);
  }

  auto sum = 0UL;
  auto const lim = 100 + B4;
  for (auto i = 0U; i < lim; i++) sum += filter2.at(i);

  cout << "Sum: " << sum << endl;
  return 0;
}
