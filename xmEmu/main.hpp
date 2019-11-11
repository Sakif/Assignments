#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include "Globals.h"
#include "cpu.h"
#include "debugger.h"

#define NUMDEVS 8

struct Emulator {
  Debugger debugger;
  CPU cpu;
};

#endif  //_MAIN_H_
