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
  // pointer to the first operand
  Formula *op1;
  // pointer to the second operand
  Formula *op2;
  // current numerical value if known
  int val;

  // character string representing the formula
  string fstr;

  // character strings representing the operands
  string fstrop1, fstrop2;

  // index of formula (if a large formula is split into subformulas)
  int find;

  // depth of the formula in the formula tree
  int depth;

  // simple constructor
  Formula() {
    val = 0;
    op1 = NULL;
    op2 = NULL;
    fstr = "";
    find = 0;
  }

  // destructor
  ~Formula() {
    //delete op1;
    //delete op2;
  }

  // method evaluate
  // it is empty here, but will be oveloaded for each type of the formula
  virtual int Evaluate() {
    return val;
  }

  virtual int Print(ostream &fs) { return 0; }

  virtual int Print(ostream &fs, int depth) { return 0; }
};

// class Variable - inheritance from Formula
class Variable : public Formula {
public:
  // constructor
  Variable(char varchar, int varval) {
    // set the character (letter) which denotes the variable

    // set the value of the variable
    val = varval;
    fstr = varchar;
    op1 = NULL;
    op2 = NULL;
    find = -1;
  }

  // a simple constructor
  Variable() {
    val = 0;
    op1 = NULL;
    op2 = NULL;
    fstr = "";
    find = -1;
  }

  int Evaluate() {
    return val;
  }

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
