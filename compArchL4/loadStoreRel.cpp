#include <iostream>

using namespace std;

/* no needed as the lab only requires us to go from instruction register to opcode

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
//*/

typedef struct {
  unsigned _dst : 3;
  unsigned _src : 3;
  unsigned _wordByte : 1;
  int _offSet : 7; /* offset is signed */
  unsigned _opcode : 2;
} LoadStoreRelative;

typedef union {
  unsigned short sh;
  LoadStoreRelative inst;
} LoadStoreRelativeOverlay;

void printinfo(LoadStoreRelativeOverlay c) {
  cout << "Instruction register: " << hex << c.sh << dec << endl;
  cout << "Dst: " << c.inst._dst << endl;
  cout << "Src: " << c.inst._src << endl;
  cout << "Word/Byte: " << c.inst._wordByte << endl;
  auto offset = static_cast<int>(c.inst._offSet);
  //cout << "Offset: " << c.inst._offSet << endl;
  cout << "Offset: " << offset << endl;
  cout << "Opcode: " << c.inst._opcode << endl;
  cout << endl;
}

int main() {
  LoadStoreRelativeOverlay code;
  code.sh = 0x810B; /* 10 0000010 0 001 011 */
  printinfo(code);
  code.sh = 0xFDC2; /* 11 1111011 1 000 010 */
  printinfo(code);
  code.sh = 0x82D3; /* 10 0000101 1 010 011 */
  printinfo(code);
  code.sh = 0x8319; /* 10 0000110 0 011 001 */
  printinfo(code);
  code.sh = 0xC183; /* 11 0000011 0 000 011 */
  printinfo(code);
  return 0;
}