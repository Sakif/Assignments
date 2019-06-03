/* see splitstring.md */

#ifndef SPLITSTRING
#define SPLITSTRING

#pragma once
#include <list>
#include <string>

using namespace std;

list<string> splitString(string line, string deliminator = " ") {
  list<string> stringTokens;
  auto start = 0U;
  auto end = line.find(deliminator);
  while (end != string::npos) {
    stringTokens.push_back(line.substr(start, end - start));
    start = end + deliminator.length();
    end = line.find(deliminator, start);
  }
  stringTokens.push_back(line.substr(start, end - start));
  return stringTokens;
}

#endif