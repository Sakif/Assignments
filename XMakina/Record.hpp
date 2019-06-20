/* ECED 3403 - XM2 Assembler Project
Sakif Fahmid Zaman - B00756635

-- Record Structure

 */

#pragma once

#include "stdio.h"
#include <iostream>
#include <string>

enum MnemonicType { Instruction,
                    Directive }; //

enum SymbolType { LBL,
                  REG,
                  UNK }; //only label (LBL) and Register (REG) sysmbols are recognized, others are unlnown (UNK)

enum RecStatus { Init,
                 ReadInput,
                 Pass1,
                 Finished }; //should be checked - as we go

//Assembly language is consists of one or more lines, where each line is a record
// Record stucture contains the information of each record
struct Record {
  std::string src, //original source line for print out later
      label,       // Name of the label, if there is one
      mnemonic,    // mnemonic name- either instruction or directive
      type,        //mnemonic type
      src_op,      //source operand
      dest_op,     //destination operand
      err_message; //error message, if something went wrong during assembly - see XM2 Assembler User Guide 2.7 Notes
  bool hasErr;     //flag to indicate if there is an error in this record
  int loc;         //location counter for this record
                   //fields for pass 2 will be added later
};

struct Symbol {
  std::string name; //name of the sysmbol
  //SymbolType type; //label (LBL), register (REG) or unknown (UNK)
  std::string type;
  std::string hex_value; //value - hex
  int dec_value;         //value - decimal
};
