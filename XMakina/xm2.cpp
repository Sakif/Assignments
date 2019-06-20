#include "Assembler.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  //check if input file is supplied

  if (argc < 2) {
    std::cout << "Not enough argument...\n (Input filename missing...)\n";
    return -1;
  }

  //looks good
  Assembler xm2 = Assembler();
  if (xm2.read_input_assembly_file(argv[1])) {
    xm2.process_lines();
    std::cout << "\nLooks good" << std::endl;
  }
  return 0;
}