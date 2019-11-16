#include <iostream>

using namespace std;

enum { REGISTER,
       CONSTANT };

enum { WORD,
       BYTE };

typedef enum { R0,
               R1,
               R2,
               R3,
               R4,
               R5,
               R6,
               R7 } Registers;

#define OP_CMP 0x45

typedef struct {
  unsigned _dst : 3;
  unsigned _src : 3;
  unsigned _wordByte : 1;
  unsigned _regCon : 1;
  unsigned _opcode : 8;
} ArithInstruction;

typedef union {
  unsigned short sh;
  ArithInstruction inst;
} ArithOverlay;

int main() {
  ArithOverlay InstructionCode;

  InstructionCode.inst._dst = R4;
  InstructionCode.inst._src = R1;
  InstructionCode.inst._wordByte = BYTE;
  InstructionCode.inst._regCon = CONSTANT;
  InstructionCode.inst._opcode = OP_CMP;

  cout << "Instruction: 0x" << hex << InstructionCode.sh << endl;

  return 0;
}