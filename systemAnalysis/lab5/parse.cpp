// Class Formula
// Object oriented C++ example
// working version 10.31.2015

// author: Dmitry Trukhachev

#include "parse.h"
#include <string>
#include "adder_class.h"
#include "formula_class.h"
#include "subinverter_class.h"

using namespace std;

Formula *parse(string fstr, Variable *vararray, int numvar, string opsigns, int &isvariable, int ndepth, int &index) {
  string fstra, fstrb, fndsign;
  int iscomplex = 0;
  Formula *Foutput = NULL;

  iscomplex = findopsign(fstr, fstra, fstrb, fndsign, "+");

  if (iscomplex == 1) {
    Foutput = new Adder(fstra, fstrb, vararray, numvar, opsigns, ndepth, index);
    isvariable = 0;
  } else {
    iscomplex = findopsign(fstr, fstra, fstrb, fndsign, "-");

    if (iscomplex == 1) {
      if (fstra.length() > 0) {
        Foutput = new Adder(fstra, "-" + fstrb, vararray, numvar, opsigns, ndepth, index);
        isvariable = 0;
      } else {
        Foutput = new Subinverter(fstrb, vararray, numvar, opsigns, ndepth, index);
        isvariable = 0;
      }
    } else {
      if ((opsigns == "-+") | (opsigns == "+-")) {
        isvariable = 1;
        Foutput = findvar(fstr, vararray, numvar);
      }
    }
  }
  return Foutput;
}

int findopsign(string fstr, string &fstr1, string &fstr2, string &foundsign, string opsigns) {
  int i = 0, foundopsign = 0;
  size_t found;

  i = fstr.length();
  while ((foundopsign == 0) & (i > -1)) {
    found = opsigns.find(fstr[i]);
    if (found != -1) {
      foundopsign = 1;
      foundsign = fstr[i];
      fstr1 = fstr.substr(0, i);
      fstr2 = fstr.substr(i + 1, fstr.length());
    }
    --i;
  }

  return foundopsign;
}

Variable *findvar(string fstri, Variable *vararray, int numvar) {
  Variable *varpointer = NULL;
  int i;

  for (i = 0; i < numvar; ++i) {
    if (vararray[i].fstr == fstri) varpointer = vararray + i;
  }
  return varpointer;
}
