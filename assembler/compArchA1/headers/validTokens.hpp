#pragma once
#include <string>

#define MAX_LABEL_LENGTH 32

using namespace std;

class validTokens {
private:
  string logFileName;

public:
  validTokens(string = "firstPass.log");
  bool constants(string, int);
  bool reg(string, int);
  bool label(string, int);
};

validTokens::validTokens(string fileName) : logFileName(fileName) {}

bool validConstant(string token, int pc) {
  auto valid = false;
  return valid;
}

bool validLabel(string token, int pc) {
  auto valid = true;                        /* the default condition */
  ofstream log(logfileName, ios_base::app); /* where to write errors */
  char c = s.at(0);                         /* the first charecter */

  if (s.length() > MAX_LABEL_LENGTH) { /* invalid if longer than the maximum label length characters */
    log << "label '" << s << "' is longer than 32 charecters at PC " << pc << endl;
    return false;
  }

  if (!isalpha(c) && c != '_') { /* invalid if first charecter is not a alphabet and not underscore */
    log << "label '" << s << "' has invalid first character at PC " << pc << endl;
    return false;
  }

  for (auto i = 1; i < s.length(); i++) { /* invalid if other are not alphanumeric and not underscore */
    c = s.at(i);
    if (!isalnum(c) && c != '_') {
      log << "label '" << s << "' has invalid characters at PC " << pc << endl;
      return false;
    }
  }
  /* every condition passed */
  log.close();
  return valid;
}
