#ifndef _CPU_H_
#define _CPU_H_
#include "Globals.h"
#include "debugger.h"
#include "instructions.h"
#include "main.h"
#include "stdio.h"

struct CPU {
  bool isRunning;
  bool exitRequired;
};

void go(Emulator &emulator);
void fetch();
void decode_and_execute();
void execute(Emulator &emulator);
void check(Emulator &emulator);

void bus(unsigned short mar, unsigned short &mbr, ACTION rw, SIZE wb);

#endif
