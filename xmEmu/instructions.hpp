#ifndef _INSTRUCTIONS_H_
#define _INSTRUCTIONS_H_

#include "Globals.h"
#include "cpu.h"

#define OPMASK(x) (((x) >> 14) & 0x03) /* B15:B14 */
#define OPBIT13(x) ((x)&0x2000)        // B13 - REG inst + special (not LDR STR)
#define OPBIT12(x) ((x)&0x1000)        //B12 - LD, ST and special (SVC and CEX)

struct PSWbits {
  unsigned _Carry : 1;
  unsigned _Zero : 1;
  unsigned _Negative : 1;
  unsigned _SLP : 1;
  unsigned _oVerflow : 1;
  unsigned _cPriority : 3;
  unsigned _notUsed : 5;
  unsigned _pPririty : 3;
};

union PswOverlay {
  short int sh;
  PSWbits bits;
};

// LD & ST INSTRUCTIONS
struct LDSTbits {
  unsigned short dst : 3;   // 000 - 111
  unsigned short src : 3;   // 000 - 111
  unsigned short wb : 2;    // 00 is byte, 01 is word
  unsigned short inc : 1;   // error if both inc
  unsigned short dec : 1;   // & dec are set
  unsigned short prpo : 1;  // 1 - PR | 0 - PO
  unsigned short type : 3;  // 000 - LD | 001 - ST
  unsigned short cat : 2;   // error if not 10
};

union LDSTOverlay {
  unsigned short inst;
  LDSTbits bits;
};

// LDR & STR INSTRUCTIONS
struct LDRSTRbits {
  unsigned short dst : 3;  // 000 - 111
  unsigned short src : 3;  // 000 - 111
  unsigned short wb : 1;   // 0 is byte, 1 is word
  unsigned short off : 6;
  unsigned short type : 1;  // 0 - LDR | 1 - STR
  unsigned short cat : 2;   // error if not 11
};

union LDRSTROverlay {
  unsigned short inst;
  LDRSTRbits bits;
};

// MOVL, MOVLZ, & MOVH INSTRUCTIONS
struct MOVbits {
  unsigned short dst : 3;   // 000 - 111
  unsigned short byte : 8;  // 0000.0000 - 1111.1111
  unsigned short type : 3;  // 100 - MOVH | 011 - MOVLZ | 010 - MOVL | 001 - ERROR
  unsigned short cat : 2;   // error if not 2
};

union MOVOverlay {
  unsigned short inst;
  MOVbits bits;
};

// BL, BEQ/BZ, BNE/BNZ, ... , & BAL INSTRUCTIONS
struct BRAbits {
  unsigned short off : 10;   // 00.0000.0000 - 11.1111.1111
  unsigned short type : 3;   // 000 - 111
  unsigned short other : 1;  // 0 if BL, 1 otherwise
  unsigned short cat : 2;    // error if not 00
};

union BRAOverlay {
  unsigned short inst;
  BRAbits bits;
};

struct ArithBits {
  unsigned short dst : 3;  // 000 - 111
  unsigned short src : 3;  // 000 - 111
  unsigned short wb : 1;   // 0 is byte, 1 is word
  unsigned short rc : 1;
  unsigned short other : 1;  // 0 if ADD-SWAP, 1 if SRA-SXT
  unsigned short type : 5;   // 0.0000 - 1.0000
  unsigned short cat : 2;    // error if not 01
};

union ArithOverlay {
  unsigned short inst;
  ArithBits bits;
};

void set_bits(ArithOverlay, unsigned short);

// DADD structures
struct DADDbits {
  unsigned short nib0 : 4;
  unsigned short nib1 : 4;
  unsigned short nib2 : 4;
  unsigned short nib3 : 4;
};

union DADDOverlay {
  unsigned short word;
  DADDbits bits;
};

void decode_execute();  // decode instruction at IR and call executioner

#endif  //_INSTRUCTIONS_H_
