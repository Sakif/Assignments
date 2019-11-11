#ifndef _LOADER_H_
#define _LOADER_H_
#include <iostream>
#include <string>

#include "cpu.h"

using namespace std;
enum SRec_Type {
  S0,
  S1,
  S9
};

struct SRec {
  SRec_Type _type;
  string _count;     //char _count[2];
  string _addr;      //char _addr[4];
  string _data;      //should be max 28 byte
  string _checksum;  //char _checksum[2];
};

bool loader(Emulator &emulator, string fname);
void read_record(SRec &rec, string line);
bool load_record(Emulator &emulator, SRec rec);
void str2int(string s, short int &value);

#endif  //_LOADER_H_
