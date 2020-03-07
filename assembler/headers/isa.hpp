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
    {"BIC", 2, false, ARITHMETIC},
    {"BIC.B", 2, false, ARITHMETIC},
    {"BIC.W", 2, false, ARITHMETIC},
    {"BIT", 2, false, ARITHMETIC},
    {"BIT.B", 2, false, ARITHMETIC},
    {"BIT.W", 2, false, ARITHMETIC},
    {"BIS", 2, false, ARITHMETIC},
    {"BIS.B", 2, false, ARITHMETIC},
    {"BIS.W", 2, false, ARITHMETIC},
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
    {"LD.B", 2, false, MEMORY},
    {"LD.W", 2, false, MEMORY},
    {"LDR", 2, false, OFFSET_MEMORY},
    {"LDR.B", 2, false, OFFSET_MEMORY},
    {"LDR.W", 2, false, OFFSET_MEMORY},
    {"MOV", 2, false, MEMORY},
    {"MOV.B", 2, false, MEMORY},
    {"MOV.W", 2, false, MEMORY},
    {"MOVLS", 2, false, MEMORY},
    {"MOVLZ", 2, false, MEMORY},
    {"ORG", 0, true, CONSTANT},
    {"RRC", 2, false, CONSTANT},
    {"RRC.B", 2, false, CONSTANT},
    {"RRC.W", 2, false, CONSTANT},
    {"SUB", 2, false, ARITHMETIC},
    {"SUB.B", 2, false, ARITHMETIC},
    {"SUB.W", 2, false, ARITHMETIC},
    {"SUBC", 2, false, ARITHMETIC},
    {"SUBC.B", 2, false, ARITHMETIC},
    {"SUBC.W", 2, false, ARITHMETIC},
    {"SRA", 2, false, OPTIONAL},
    {"SRA.B", 2, false, OPTIONAL},
    {"SRA.W", 2, false, OPTIONAL},
    {"ST", 2, false, MEMORY},
    {"ST.B", 2, false, MEMORY},
    {"ST.W", 2, false, MEMORY},
    {"STR", 2, false, OFFSET_MEMORY},
    {"STR.B", 2, false, OFFSET_MEMORY},
    {"STR.W", 2, false, OFFSET_MEMORY},
    {"SWAP", 2, false, NO_OP},
    {"SWPB", 2, false, NO_OP},
    {"SWPB.W", 2, false, NO_OP},
    {"WORD", 0, true, CONSTANT},
    {"XOR", 2, false, ARITHMETIC},
    {"XOR.B", 2, false, ARITHMETIC},
    {"XOR.W", 2, false, ARITHMETIC}};
/*
SXT 0100111110000 r 
SXT.W 0100111110000 r 
SVC 010110000000 s 
CEX 010111 c,t,t
MOVL 01100 b,r 

MOVH 01110 b,r 
*/
instruction findISA(string);

#endif
