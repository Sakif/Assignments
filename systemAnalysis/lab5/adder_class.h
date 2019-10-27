// Class Formula
// Object oriented C++ example
// working version 10.31.2015

// author: Dmitry Trukhachev

#include "formula_class.h"
#include "parse.h"
#include <string>

using namespace std;

#ifndef _adder_h_
#define _adder_h_

// class Adder - inheritance from Formula
class Adder : public Formula {
public:
  // flags stating if the first or second operand is a variable
  int op1var, op2var;

  //----------------------------------------------------------
  // constructor that specifies the character string representing the formula
  // and creates the formula object and all the subformulas within
  //
  // input
  // pointer to the string representing the formula
  // pointer to an array of Variable classes that are used within the Formula
  //Adder(string fstr1, string fstr2, Variable* vararray, int numvar, string opsigns);

  // constructor using function parse()
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

  // method evaluate
  int Evaluate() {
    val = op1->Evaluate() + op2->Evaluate();
    return val;
  }

  int Print(ostream &fs) {
    int a;
    fs << "depth " << depth << " Adder " << find << " ; " << fstrop1 << "  +  " << fstrop2 << ";   value = " << val << "." << endl;

    //a = op1->Print(fs);
    if (op1var == 0) {
      a = op1->Print(fs);
    } else {
      a = op1->Print(fs, depth + 1);
    }
    //a = op2->Print(fs);
    if (op2var == 0) {
      a = op2->Print(fs);
    } else {
      a = op2->Print(fs, depth + 1);
    }

    return 0;
  }
};

//int findopsign(string fstr, string& fstr1, string& fstr2, string& foundsign, string opsigns);
//Variable* findvar(string fstri, Variable* vararray, int numvar);

#endif

// to add subtractor we can inherit from formula AdderSub (adder and subtractor)
// in the constructor of it if we get iscomplex and "-" is the operation sign ...
// since adder call only adder constructor it cannot be used if we need subtraction
//
// create fn print (to cout)
// read f-la from file (stream)
//