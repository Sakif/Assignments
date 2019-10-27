// Program for parsing a formula
// Object oriented C++ eaxample project
//
// This version,
// started 10.31.2015
#include "adder_class.h"
#include "formula_class.h"
#include <iostream>
#include <string>

using namespace std;

// file with the simulation parameters
char *FormulaFile = "formula_string.dat";

// *************************************************************************************

int main(int argc, char **argv) {
  int i, numvar, isvariable, index = 0;

  // parameter data -----------------------------------------------------
  numvar = 3;
  // array of variables
  Variable Vars[3];
  // defining variables
  Vars[0].fstr = "x";
  Vars[1].fstr = "y";
  Vars[2].fstr = "z";
  // a list of valid operation signs
  string opsnn = "+-";

  // testing ------------------------------------------------------------
  // test formula string
  string testform = "x+y+x+z+z+y+x+z+y";

  // find the first operation sign and create
  Formula *myAd;
  myAd = parse(testform, Vars, numvar, opsnn, isvariable, 0, index);

  // assigning values to variables
  Vars[0].val = 1;
  Vars[1].val = 2;
  Vars[2].val = 3;

  cout << "Evaluated Formula = " << myAd->Evaluate() << endl
       << endl;

  // output formula to the screen
  myAd->Print(cout);

  // output fromula to a file
  fstream Fout;
  Fout.open("outputfile.txt", fstream::out);
  myAd->Print(Fout);
  cin >> i;

  Fout.close();
  delete myAd;

  return 0;
}

//************************************************************************************
