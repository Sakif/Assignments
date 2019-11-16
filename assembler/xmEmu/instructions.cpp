#include "instructions.h"

void reg_const_ops() {}

void ldr_str_ops() {
  PswOverlay psw;
  psw.sh = PSW;
  LDRSTROverlay ldrstr;
  ldrstr.inst = IR;
  unsigned short EA;
#ifdef DEBUG
  printf("\nExecuting LDRSTR type instruction");
  printf("\nDST %d SRC %d OFF %d", ldrstr.dst, ldrstr.src, ldrstr.off);
#endif

  TMP = ldrstr.bits.off;
  if (CHECK_BIT(TMP, 6))
    TMP |= 0xFFE0;

  if (ldrstr.bits.type == 1) {
    EA = reg_file[0][ldrstr.bits.src] + TMP;
    MAR = EA;
    MBR = reg_file[0][ldrstr.bits.dst];
    if (ldrstr.bits.wb == 0)
      bus(MAR, MBR, READ, WORD);
    else
      bus(MAR, MBR, READ, BYTE);
  } else if (ldrstr.bits.type == 0) {
    EA = reg_file[0][ldrstr.bits.dst] + TMP;
    MAR = EA;
    MBR = reg_file[0][ldrstr.bits.src];
    if (ldrstr.bits.wb == 0)
      bus(MAR, MBR, WRITE, WORD);
    else
      bus(MAR, MBR, WRITE, BYTE);
  }
  return;
}

void decode_execute() {
  switch (OPMASK(IR)) {
    case 0:
      branch_ops();
      break;
    case 1:
      if (OPBIT13(IR))
        mov_ops();
      else if (OPBIT12(IR))
        ld_st_special();
      else
        reg_const_ops();
      break;
    case 2:  //LDR access
    case 3:  //STR access
      ldr_str_ops();
      break;
  }
}
