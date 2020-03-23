#pragma once
#include "all.hpp"

using namespace std;

#ifndef COMMANDS_H
#define COMMANDS_H

#define COMMAND_TABLE_SIZE 83
#define COMMAND_NOT_FOUND -1

enum CommandType {
  DIRECTORY,
  INSTRUCTION
};

enum OperandType {
  NONE,
  CR_R,
  R_R,
  C,
  R,
  Opt,
  V,
  CEXop,
  SA,
  LDop,
  STop,
  LDRop,
  STRop,
  BRAop,
  BRA13,
  V_R
};

enum OpSize {
  W,
  B
};

enum CommandEnum {
  ADD,
  ADD_B,
  ADD_W,
  ADDC,
  ADDC_B,
  ADDC_W,
  ALIGN,
  AND,
  AND_B,
  AND_W,
  BC,
  BEQ,
  BGE,
  BHS,
  BIC,
  BIC_B,
  BIC_W,
  BIS,
  BIS_B,
  BIS_W,
  BIT,
  BIT_B,
  BIT_W,
  BL,
  BLO,
  BLT,
  BN,
  BNC,
  BNE,
  BNZ,
  BRA,
  BSS,
  BYTE,
  BZ,
  CEX,
  CMP,
  CMP_B,
  CMP_W,
  DADD,
  DADD_B,
  DADD_W,
  END,
  EQU,
  LD,
  LD_B,
  LD_W,
  LDR,
  LDR_B,
  LDR_W,
  MOV,
  MOV_B,
  MOV_W,
  MOVH,
  MOVL,
  MOVLS,
  MOVLZ,
  ORG,
  RRC,
  RRC_B,
  RRC_W,
  SRA,
  SRA_B,
  SRA_W,
  ST,
  ST_B,
  ST_W,
  STR,
  STR_B,
  STR_W,
  SUB,
  SUB_B,
  SUB_W,
  SUBC,
  SUBC_B,
  SUBC_W,
  SVC,
  SWAP,
  SWPB,
  SXT,
  WORD,
  XOR,
  XOR_B,
  XOR_W
};

struct Command {
  string name;
  CommandType type;
  int opCount;
  OperandType ops;
  OpSize wb;
  unsigned int pcIncriment;
};

extern Command commands[COMMAND_TABLE_SIZE];

int checkTable(string);

#endif
