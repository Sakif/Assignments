// Class Formula
// Object oriented C++ example
// working version 10.31.2015

// author: Dmitry Trukhachev

#include "parse.h"
#include "adder_class.h"
#include "formula_class.h"
#include "subinverter_class.h"
#include <string>

using namespace std;

// input - string to parse
// variable array, it length
// operation signs
// output - pointer to a created formula, flag if it is a fariable
Formula *parse(string fstr, Variable *vararray, int numvar, string opsigns, int &isvariable, int ndepth, int &index) {
  string fstra, fstrb, fndsign;
  // a flag if the formula consists of two operands and an opration sign in it
  int iscomplex = 0;

  Formula *Foutput = NULL;

  // process the string fstr ----------------------------------------------------------
  // check if it is in compex form (not a variable)
  iscomplex = findopsign(fstr, fstra, fstrb, fndsign, "+");

  if (iscomplex == 1) {
    // we have a formula with two operands and it is an adder
    Foutput = new Adder(fstra, fstrb, vararray, numvar, opsigns, ndepth, index);
    isvariable = 0;
  } else {
    // if "+" is not found it should be a variable or contain
    // other signs
    // we check for "-" sign
    iscomplex = findopsign(fstr, fstra, fstrb, fndsign, "-");

    if (iscomplex == 1)
    // the "-" is found
    {
      if (fstra.length() > 0) {
        // we have a formula with "-" and that "-" is not the first symbol in the string
        // for example XXX-XXX-XXX
        // then we create an Adder and the second operand has the "-" in front of it
        Foutput = new Adder(fstra, "-" + fstrb, vararray, numvar, opsigns, ndepth, index);
        isvariable = 0;
      } else {
        // the formula is of the form -XXXXX
        // we call the subinverter
        Foutput = new Subinverter(fstrb, vararray, numvar, opsigns, ndepth, index);
        isvariable = 0;
      }
    } else {
      // no other signs possible ?
      if ((opsigns == "-+") | (opsigns == "+-")) {
        // is it a variable
        // check the list of variables, find it and point the first operand int it
        isvariable = 1;
        Foutput = findvar(fstr, vararray, numvar);
      }
    }
  }

  return Foutput;
}

int findopsign(string fstr, string &fstr1, string &fstr2, string &foundsign, string opsigns) {
  // the function looks to find the first sign of any operation in fstr ----------
  // it searches over all possible operation signs in the array opsigns
  // and once it found one
  // it returs :
  // foundopsign = the operation sign
  // the first and second operand strings = fstr1 and fstr2, the flag iscomplexform = 1
  //
  // otherwise if nothing found the flag iscomplexform = 0

  // now the function works backwards from i = fstr.length-1 down to 0
  int i = 0, foundopsign = 0;
  size_t found;

  i = fstr.length();
  while ((foundopsign == 0) & (i > -1)) {
    found = opsigns.find(fstr[i]);
    if (found != -1) {
      // change the found flag to 1
      foundopsign = 1;
      // collect the operation sign that was found
      foundsign = fstr[i];
      // collect the two remaining strings - operands
      fstr1 = fstr.substr(0, i);
      fstr2 = fstr.substr(i + 1, fstr.length());
    }
    --i;
  }

  return foundopsign;
}

// find the variable denoed by 'fstri'
Variable *findvar(string fstri, Variable *vararray, int numvar) {
  Variable *varpointer = NULL;
  int i;

  for (i = 0; i < numvar; ++i) {
    if (vararray[i].fstr == fstri)
      varpointer = vararray + i;
  }
  return varpointer;
}
