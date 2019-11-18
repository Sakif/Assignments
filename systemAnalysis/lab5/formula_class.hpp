// Class Formula
// Object oriented C++ example
// working version 10.31.2015

// author: Dmitry Trukhachev

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#ifndef _formula_h_
#define _formula_h_

class Formula {
public:
  Formula *op1, *op2;
  int val, find, depth;
  string fstr, fstrop1, fstrop2;

  Formula() {
    val = 0;
    op1 = NULL;
    op2 = NULL;
    fstr = "";
    find = 0;
  }

  ~Formula() {}

  virtual int Evaluate() { return val; }

  virtual int Print(ostream &fs) { return 0; }

  virtual int Print(ostream &fs, int depth) { return 0; }
};

class Variable : public Formula {
public:
  Variable(char varchar, int varval) {
    val = varval;
    fstr = varchar;
    op1 = NULL;
    op2 = NULL;
    find = -1;
  }

  Variable() {
    val = 0;
    op1 = NULL;
    op2 = NULL;
    fstr = "";
    find = -1;
  }

  int Evaluate() { return val; }

  int Print(ostream &fs) {
    fs << "Variable " << fstr << " = " << val << " ." << endl;
    return 0;
  }

  int Print(ostream &fs, int depth) {
    fs << "depth " << depth << " Variable " << fstr << ";   value = " << val << "." << endl;
    return 0;
  }
};

#endif
