#include <list>
#include <regex>
#include <string>

using namespace std;

list<string> resplit(const string &str, string re = "\\s+") {
  list<string> tokens;
  regex rgx(re);

  sregex_token_iterator iter(str.begin(), str.end(), rgx, -1);
  sregex_token_iterator end;
  while (iter != end) {
    tokens.push_back(*iter);
    iter++;
  }
  return tokens;
}
