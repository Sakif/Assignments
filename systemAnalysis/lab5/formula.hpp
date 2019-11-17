/*
Author: Sakif Fahmid Zaman
*/

#pragma once

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#ifndef FORMULA
#define FORMULA

class formula {
public:
  formula *op1, *op2;
  int value, find, depth;
  string formulaString, formulaOparand1String, formulaOparand2String;

  formula();
  ~formula();

  int evaluate();
  int print(ostream &);
  int print(ostream &, int);
};

formula::formula() {
  op1 = nullptr;
  op2 = nullptr;
  value = 0;
  find = 0;
  formulaString = "";
}

int formula::evaluate() { return value; }

int formula::print(ostream &fs) { return 0; }

int formula::print(ostream &fs, int depth) { return 0; }

#endif
