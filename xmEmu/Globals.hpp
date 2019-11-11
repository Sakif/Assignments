#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <bitset>

enum SIZE { WORD,
            BYTE };
enum ACTION { READ,
              WRITE };

#define INSTSIZE 2

#define BYTEMAXMEM (1 << 16)
#define WORDMAXMEM (1 << 15)
#define VECTORBASE 0xFFC0
#define DEVMEM 0x0010

union mem_ex {
  unsigned char byte_mem[BYTEMAXMEM];
  unsigned short word_mem[WORDMAXMEM];
};

extern union mem_ex memory;
#define REGCNT 8
#define ROWS 2

extern unsigned reg_file[ROWS][REGCNT];

#define LR reg_file[0][4]
#define SP reg_file[0][5]
#define PSW reg_file[0][6]
#define PC reg_file[0][7]

extern unsigned carry[2][2][2];
extern unsigned overflow[2][2][2];

extern unsigned short MAR;
extern unsigned short MBR;
extern unsigned short IR;
extern unsigned short TMP;

extern short int sysclk;

#define CHECK_BIT(var, pos) (((var) & (1 << pos)) >> pos)
#define SET_BIT(var, pos, val) ((var) |= (val << pos))

#define SEXT_BL 0xE000
#define SEXT_BR 0xF800

#define LO_BYTE 0x00FF
#define HI_BYTE 0xFF00

#endif
