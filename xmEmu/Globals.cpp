#include "Globals.hpp"

#define DEBUG

union memory_ex memory;

short int sysclk = 0;  //system clock counter
unsigned reg_file[ROWS][REGCNT] = {
    {0, 0, 0, 0, 0, 0, 0, 0},    //initial REG contents
    {0, 1, 2, 4, 8, 32, 48, -1}  //constants
};

unsigned carry[2][2][2] = {0, 0, 1, 0, 1, 0, 1, 1};
unsigned overflow[2][2][2] = {0, 1, 0, 0, 0, 0, 1, 0};

unsigned short MAR = 0;
unsigned short MBR = 0;
unsigned short IR = 0;
unsigned short TMP = 0;
