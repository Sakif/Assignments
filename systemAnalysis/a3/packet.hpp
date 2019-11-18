#pragma once
#include "start.hpp"

using namespace std;

#ifndef PACKET
#define PACKET

class packet {
private:
  int _preamble;
  int _ID;
  int _data;

public:
  packet(int, int, int);
  int preamble() const;
  int ID() const;
  int data() const;
};

#endif
