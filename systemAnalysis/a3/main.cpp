#include <iostream>
#include <string>

#include "SimObj.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
  //cout << "Hello World!" << endl;

  SimObj sim("input.txt");  // = new SimObj("input.txt");
  sim.getData();
  sim.runSimulation();
  sim.write_to_output();
  return 0;
}
