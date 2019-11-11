#include "cpu.h"

void dev_mem_access(unsigned short mar, unsigned short &mbr, ACTION rw, SIZE wb) {
  //TODO
}

void bus(unsigned short mar, unsigned short &mbr, ACTION rw, SIZE wb) {
  if (rw == READ)
    mbr = (wb == WORD) ? memory.word_mem[mar >> 1] : memory.byte_mem[mar];
  else {  //rw == WRITE
    if (wb == WORD)
      memory.word_mem[mar >> 1] = mbr;
    else  //BYTE
      memory.byte_mem[mar] = (unsigned char)(mbr & 0xFF);
  }
  if (mar < DEVMEM)
    dev_mem_access(mar, mbr, rw, wb);  //this part is not implemented - a dummy function is placed instead TODO: if time permits
  if (mar < VECTORBASE)
    sysclk += 3;
}

void go(Emulator &emulator) {
  debug(emulator);
  emulator.cpu.isRunning = true;
  emulator.cpu.exitRequired = false;
  for (;;) {
    fetch();
    decode_and_execute();  //(emulator);
    //execute(emulator);
    check(emulator);  //
    if (emulator.cpu.exitRequired)
      break;
  }
}

void fetch() {
  MAR = PC;
#ifdef DEBUG
  printf("\nFetching from location 0x%x", MAR);
#endif
  bus(MAR, MBR, READ, WORD);
  IR = MBR;
  PC += INSTSIZE;
  SET_BIT(PC, 0, 0);
  return;
}

void decode_and_execute() {
  decode_execute();
}

void execute(Emulator &emulator);
void check(Emulator &emulator);
