#ifndef __SIMOBJ_H__
#define __SIMOBJ_H__

#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class SimObj {
public:
  // SimObj() { };
  // defualt constructor to populalate simulation object with parameters and
  // pkts' arrival information
  // provided in the input file following the assignment outline -default input
  // file name is "input.txt"
  SimObj(string s1 = "input.txt", string s2 = "output.txt") : in_fname(s1), out_fname(s2){};
  void getData();
  void runSimulation();  // function to run simulation
  void write_to_output();

private:
  int L, /* # of bits in the preamble in each data pkt - no bit of a preamble from one pkt should be overlapped with any bit of other preamble for successful detection */
      I, /* # of bits in each data pkt to indicate ID of the src */
      M, /* required for preamble detection - any one bit in a preamble can not interfere more than (M-1) ohter pkt's ID (I bits) or data portions (N bits) */
      N, /* each pkt contains N bits of data */
      Q, /* for ID decoding - no more than (Q-1) bits from other preamble/ID/data bits are allowed for successfull decoding of ID portion of a pkt */
      P, /* for data decoding - no more than (P-1) bits from other preamble/ID/data bits are allowed for successfull decoding of Data portion of a pkt */
      n; /* number of pkts to be cosidered */

  std::vector<int> arr_times;  // this vector contains simplified arrival time of pkts
  string in_fname;             // input file name
  string out_fname;            // output file name
  std::vector<char> pkt_status;

  // private methods
  bool isDetected(int pkt_number);
  vector<int> getPreambleOverlapTimes(int pkt1, int pkt2);
  vector<int> getP_IdDataOverlapTimes(int pkt_prev, vector<int> curr);
  //
  bool isIDDecoded(int pkt_idx);
  vector<int> getID_PktOverlapTimes(int other_pkt, vector<int> curr);

  bool isDataDecoded(int pkt_idx);
  vector<int> getData_PktOverlapTimes(int other_pkt, vector<int> curr);
};

#endif  //__SIMOBJ_H__
