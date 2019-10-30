// Class Formula
// Object oriented C++ example
// working version 10.31.2015

// author: Dmitry Trukhachev

#include <string>
#include "formula_class.h"
#include "parse.h"

using namespace std;

#ifndef _adder_h_
#define _adder_h_

// class Adder - inheritance from Formula
class Adder : public Formula {
 public:
  int op1var, op2var;
  Adder(string fstr1, string fstr2, Variable *vararray, int numvar, string opsigns, int ndepth, int &index) {
    find = ++index;
    // create the first and second operand using the parse f-n
    op1 = parse(fstr1, vararray, numvar, opsigns, op1var, ndepth + 1, index);
    op2 = parse(fstr2, vararray, numvar, opsigns, op2var, ndepth + 1, index);
    val = 0;
    // set members
    fstr = fstr1 + "+" + fstr2;
    depth = ndepth;
    fstrop1 = fstr1;
    fstrop2 = fstr2;
  }

  ~Adder() {
    if (op1var == 0)
      delete op1;
    if (op2var == 0)
      delete op2;
  }

  int Evaluate() {
    val = op1->Evaluate() + op2->Evaluate();
    return val;
  }

  int Print(ostream &fs) {
    int a;
    fs << "depth " << depth << " Adder " << find << " ; " << fstrop1 << "  +  " << fstrop2 << ";   value = " << val << "." << endl;

    if (op1var == 0)
      a = op1->Print(fs);
    else
      a = op1->Print(fs, depth + 1);

    if (op2var == 0)
      a = op2->Print(fs);
    else
      a = op2->Print(fs, depth + 1);

    return 0;
  }
};

#endif
