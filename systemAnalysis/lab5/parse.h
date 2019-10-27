// Class Formula
// Object oriented C++ example
// working version 10.31.2015

// author: Dmitry Trukhachev

#include "formula_class.h"
#include <string>
//#include "adder_class.h"

using namespace std;

#ifndef _parse_h_
#define _parse_h_

// parses the string fstr and creates a formula object for it
Formula *parse(string fstr, Variable *vararray, int numvar, string opsigns, int &isvariable, int ndepth, int &index);

int findopsign(string fstr, string &fstr1, string &fstr2, string &foundsign, string opsigns);
Variable *findvar(string fstri, Variable *vararray, int numvar);

#endif
