/* ECED 3403 - XM2 Assembler Project
Sakif Fahmid Zaman - B00756635

-- XM2 Assembler Class

 */

#pragma once

#include "stdio.h"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "Record.hpp"
#include "Utility.hpp"

//The assebler class is the heart of the
class Assembler {
  //fields
private:
  //vars
  std::string fname;                  //file name - different filenames will be generated based on input file name
  std::vector<std::string> raw_lines; //from input file to collection of lines
  std::vector<Symbol> SymTab;         //symbol table
  std::vector<Record> records;        //records in an .asm file - later it will be processed in pass1 and pass2 phase
  std::vector<std::string> InstructionSet;
  std::vector<std::string> Directives;
  const char comment_char = ';';                       //comment character
                                                       //methods
  std::string check_token(std::string);                //determine if the string is a mnemonic and its type
  std::vector<std::vector<std::string>> get_cleaned(); //clean up raw source lines and returns only the
  bool pass1(std::vector<std::vector<std::string>>);   // first pass of the xm2 assembler - ref: Sec 5.2 User's Guide
  std::string validate_label(std::string);

public:
  //constructors
  Assembler();            //default XM2 behaviour (Instructions and Directives) will be loaded
  Assembler(std::string); //if the default behavior is changed, the new Instruction sets can be declared through a file
  //methods
  bool read_input_assembly_file(std::string); //read and input file and populate lines in the records - first step
  void process_lines();                       //process all the raw line to separate labels, instruction/directive and operands to create record
};