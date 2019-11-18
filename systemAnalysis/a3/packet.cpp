#include "packet.hpp"

packet::packet(int p, int i, int d) : _preamble(p), _ID(i), _data(d) {}

int packet::preamble() const { return _preamble; }

int packet::ID() const { return _ID; }

int packet::data() const { return _data; }
