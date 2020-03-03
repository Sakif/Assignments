#pragma once
#include "definitions.hpp"

using namespace std;

#ifndef INSTRUCTION
#define INSTRUCTION

enum operand {
  NO_OP,
  OPTIONAL,
  CONSTANT,
  ARITHMETIC,
  BRANCH,
  REG,
  LONG_BRANCH,
  MEMORY,
  OFFSET_MEMORY
};

struct instruction {
  string name;
  int pcIncrement;
  bool directory;
  operand op;
};

const vector<instruction> isaTable = {
    {"ADDC", 2, false, ARITHMETIC},
    {"ADDC.B", 2, false, ARITHMETIC},
    {"ADDC.W", 2, false, ARITHMETIC},
    {"ADD", 2, false, ARITHMETIC},
    {"ADD.B", 2, false, ARITHMETIC},
    {"ADD.W", 2, false, ARITHMETIC},
    {"AND", 2, false, ARITHMETIC},
    {"AND.B", 2, false, ARITHMETIC},
    {"AND.W", 2, false, ARITHMETIC},
    {"BC", 2, false, BRANCH},
    {"BEQ", 2, false, BRANCH},
    {"BGE", 2, false, BRANCH},
    {"BHS", 2, false, BRANCH},
    {"BL", 2, false, LONG_BRANCH},
    {"BLO", 2, false, BRANCH},
    {"BLT", 2, false, BRANCH},
    {"BNC", 2, false, BRANCH},
    {"BN", 2, false, BRANCH},
    {"BNE", 2, false, BRANCH},
    {"BNZ", 2, false, BRANCH},
    {"BRA", 2, false, BRANCH},
    {"BZ", 2, false, BRANCH},
    {"CMP", 2, false, ARITHMETIC},
    {"CMP.B", 2, false, ARITHMETIC},
    {"CMP.W", 2, false, ARITHMETIC},
    {"DADD", 2, false, ARITHMETIC},
    {"DADD.B", 2, false, ARITHMETIC},
    {"DADD.W", 2, false, ARITHMETIC},
    {"END", 2, false, OPTIONAL},
    {"LD", 2, false, MEMORY},
    {"MOVLS", 2, false, MEMORY},
    {"MOVLZ", 2, false, MEMORY},
    {"ORG", 0, true, CONSTANT},
    {"SUB", 2, false, ARITHMETIC},
    {"SUB.B", 2, false, ARITHMETIC},
    {"SUB.W", 2, false, ARITHMETIC},
    {"SUBC", 2, false, ARITHMETIC},
    {"SUBC.B", 2, false, ARITHMETIC},
    {"SUBC.W", 2, false, ARITHMETIC},
    {"ST", 2, false, MEMORY},
    {"WORD", 0, true, CONSTANT},
    {"XOR", 2, false, ARITHMETIC},
    {"XOR.B", 2, false, ARITHMETIC},
    {"XOR.W", 2, false, ARITHMETIC}};
/*
BIT 01001000 v,r 
BIT.B 01001000 v,r 
BIT.W 01001000 v,r 
BIC 01001001 v,r 
BIC.B 01001001 v,r 
BIC.W 01001001 v,r 
BIS 01001010 v,r 
BIS.B 01001010 v,r 
BIS.W 01001010 v,r 
MOV 01001011 v,r 
MOV.B 01001011 v,r 
MOV.W 01001011 v,r 
SWAP 01001100 r,r 
SRA 010011010 r 
SRA.B 010011010 r 
SRA.W 010011010 r 
RRC 010011100 r 
RRC.B 010011010 r 
RRC.W 010011010 r 
SWPB 0100111100000 r 
SWPB.W 0100111100000 r 
SXT 0100111110000 r 
SXT.W 0100111110000 r 
SVC 010110000000 s 
LD 010100 p,r 
LD.B 010100 p,r 
LD.W 010100 p,r 
ST 010101 r,p
ST.B 010100 r,p
ST.W 010100 r,p
CEX 010111 c,t,t
MOVL 01100 b,r 
MOVLZ 01101 b,r 
MOVLS 01110 b,r 
MOVH 01110 b,r 
LDR 10 r,o,r 
LDR.B 10 r,o,r 
LDR.W 10 r,o,r 
STR 11 r,r,o 
STR.B 11 r,r,o 
STR.W 11 r,r
*/
instruction findISA(string);

#endif
