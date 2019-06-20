#include "Utility.hpp"

std::vector<std::string> split(std::string str2split, char delimeter) {
  std::stringstream ss(str2split);
  std::string item;
  std::vector<std::string> splittedStrings;
  while (std::getline(ss, item, delimeter)) {
    splittedStrings.push_back(item);
  }

  return splittedStrings;
}

std::string removeComment(std::string s) { //considering the comment char is ";"
  if (!s.empty()) {                        //s not empty
    std::string delim = ";";
    return s.substr(0, s.find_first_of(delim));
  } else {
    return s;
  }
}
