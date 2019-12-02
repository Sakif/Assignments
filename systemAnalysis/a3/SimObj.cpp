#include "SimObj.h"

void SimObj::getData() {
  ifstream ifs;        //create an input file stream
  ifs.open(in_fname);  //open the file and attach it to ifs

  //read from file and assign values accordingly

  ifs >> L;
  ifs >> I;
  ifs >> M;
  ifs >> N;
  ifs >> Q;
  ifs >> P;
  ifs >> n;
  //read arrival times
  int atime;  //var to get arrival time of each pkt
  arr_times = vector<int>{};
  //read first pkt's arrival time
  ifs >> atime;
  arr_times.push_back(atime);
  //read rest of the data and check for error
  for (int i = 1; i < n; i++) {
    ifs >> atime;
    if (atime < arr_times[i - 1]) cout << " Error in pkt arrival time" << endl;
    arr_times.push_back(atime);
  }
  ifs.close();
  //print all data for sanity check

  std::cout << L << ", " << I << ", " << M << ", " << N << ", " << Q << ", " << P << ", " << n << endl;
  cout << "Arrival times:" << endl;
  for (auto d : arr_times) cout << d << endl;
}

//check overlapped time-slots between ID and others pkts

vector<int> SimObj::getID_PktOverlapTimes(int other_pkt, vector<int> curr) {
  //other pkt's  time slots
  std::vector<int> pkt(L + I + N + 1);                      // L+I+N bits
  std::iota(pkt.begin(), pkt.end(), arr_times[other_pkt]);  //populate

  cout << "\n Pkt# " << other_pkt << " size: " << pkt.size() << endl;

  cout << "\n Pkt# " << other_pkt << " spans: (";
  for (auto d : pkt) cout << d << ", ";

  cout << ") time slots" << endl;

  //get intersection - to check any overlap in time slots
  std::vector<int> v(L + I + N + 1);  //vector for storing intersection between ID (curr) and other_pkt

  auto it = std::set_intersection(curr.begin(), curr.end(), pkt.begin(), pkt.end(), v.begin());

  v.resize(it - v.begin());

  return v;
}

//check overlapped time-slot(s) between a preamble and ID/Data bit from a prev pkt

vector<int> SimObj::getP_IdDataOverlapTimes(int pkt_prev, vector<int> curr) {
  //prev pkt's  ID+Data time slots
  std::vector<int> IdData(I + N);                                            // I+N bits preamble
  std::iota(std::begin(IdData), std::end(IdData), arr_times[pkt_prev] + L);  //populate

  //print IdData time-occupancy
  cout << "\nId+Data of pkt " << pkt_prev << " spans: (";
  for (auto d : IdData) cout << d << ", ";

  cout << ") time slots" << endl;

  //get intersection - to check any overlap in time slots
  std::vector<int> v(L + I + N);  //vector for storing intersection of preambles
  //std::vector<int>::iterator it;

  auto it = std::set_intersection(curr.begin(), curr.end(), IdData.begin(), IdData.end(), v.begin());

  v.resize(it - v.begin());

  return v;
}

// check overlap between two preambles
vector<int> SimObj::getPreambleOverlapTimes(int pkt1, int pkt2) {
  //pkt1 preamble time slots
  std::vector<int> preamble_1(L);                                            // L bits preamble
  std::iota(std::begin(preamble_1), std::end(preamble_1), arr_times[pkt1]);  //populate

  //print preambles time-occupancy
  cout << "\nPreamble of pkt " << pkt1 << " spans: (";
  for (auto d : preamble_1) cout << d << ", ";

  cout << ") time slots" << endl;
  //pkt2 preamble time slots
  std::vector<int> preamble_2(L);                                            // L bits preamble
  std::iota(std::begin(preamble_2), std::end(preamble_2), arr_times[pkt2]);  //populate

  //print preambles time-occupancy
  cout << "\nPreamble of pkt " << pkt2 << " spans: (";
  for (auto d : preamble_2) cout << d << ", ";

  cout << ") time slots" << endl;

  //get intersection - to check any overlap in time slots
  std::vector<int> v(L);  //vector for storing intersection of preambles
  //std::vector<int>::iterator it;

  auto it = std::set_intersection(preamble_1.begin(), preamble_1.end(), preamble_2.begin(), preamble_2.end(), v.begin());

  v.resize(it - v.begin());

  return v;
}

/*  This function calculates whether a pkt's preamble is succesfully  detected or not
   INPUT: the index of the pkt in the arr_times array - pkts preamble to be detected
   OUTPUT: bool (T/F) whether it is successfully detected or not based on the conditions outlined in the assignment

*/
bool SimObj::isDetected(int pkt_idx) {
  //step 1: check if preambbles from other pkts overlaps
  //        assumption: if preambles of immidaiately prev or next pkt does not overlap,
  //        preambles of other pkts will not overlap too - so, check for the overlapping of prev and next pkts
  bool isPreambleOverlapped = false;
  vector<int> ov;      //overlapped vector
  if (pkt_idx == 0) {  //first pkt - no prev pkt, check only next pkt preamble

    ov = getPreambleOverlapTimes(0, 1);  //overlapped vector

    if (ov.size() != 0) isPreambleOverlapped = true;  //first and 2nd preambles overlapped - can't be detected

    /* cout << "Preambles of pkts " << pkt_idx << " and " << pkt_idx + 1 << " overlapped at :";
    for (auto d : ov)
      std::cout << ' ' << d;
    std::cout << '\n'; */

  } else if (pkt_idx == arr_times.size() - 1) {  //last pkt, no next pkt, check only prev pkt

    ov = getPreambleOverlapTimes(pkt_idx, pkt_idx - 1);  //overlapped vector

    if (ov.size() != 0) isPreambleOverlapped = true;  // last and just prev pkt preambles overlapped - can't be detected

    /*
    cout << "Preambles of pkts " << pkt_idx << " and " << pkt_idx - 1 << " overlapped at :";
    for (auto d : ov)
      std::cout << ' ' << d;
    std::cout << '\n';
*/

  } else {  //otherwise, check both prev and next preambles

    //prev
    ov = getPreambleOverlapTimes(pkt_idx, pkt_idx + 1);  //overlapped vector

    if (ov.size() != 0) isPreambleOverlapped = true;  //this pkt  and the prev pkt  preambles overlapped - can't be detected

    // cout << "Preambles of pkts " << pkt_idx << " and " << pkt_idx +1 << " overlapped at :";
    // for ( auto d : ov)
    // 	std::cout << ' ' << d;
    // std::cout << '\n';

    //next
    ov = getPreambleOverlapTimes(pkt_idx, pkt_idx - 1);  //overlapped vector

    if (ov.size() != 0) isPreambleOverlapped = true;  // last and just prev pkt preambles overlapped - can't be detected

    /* cout << "Preambles of pkts " << pkt_idx << " and " << pkt_idx - 1 << " overlapped at :";
    for (auto d : ov)
      std::cout << ' ' << d;
    std::cout << '\n';*/
  }

  if (isPreambleOverlapped)
    return false;  //overlapped preambles - no need to check further

  else { /* prev pkts those are transmitted after a pkt lenth (L+I+N) but before preamble lenth (L) (in this case preambles interfere with each other) so, if prev pkts arrival is within less than pkt len - we will consider this case */
    if (pkt_idx == 0)
      return true; /* if preamble interference didnot occur -Id + Data interfernec will not occur either fro the first pkt */

    else {  //current pkt's preamble time slots

      // L bits preamble
      std::vector<int> preamble_curr(L);
      //populate
      std::iota(std::begin(preamble_curr), std::end(preamble_curr), arr_times[pkt_idx]);

      //print preambles time-occupancy
      cout << "at overlap preamble vs id_data" << endl;
      cout << "\nPreamble of pkt " << pkt_idx << " spans: (";
      for (auto d : preamble_curr)
        cout << d << ", ";
      cout << ") time slots" << endl;

      vector<int> v;
      vector<int> overlap_count(L);

      for (int j = 0; j < pkt_idx; j++) {
        if ((arr_times[pkt_idx] - arr_times[j] < (L + N + I)) && (arr_times[pkt_idx] - arr_times[j] > L)) {
          //find overlapped time slots and increase count
          cout << "prev pkt # that overlapped " << j << endl;
          v = getP_IdDataOverlapTimes(j, preamble_curr);
          if (v.size() != 0) {  //inference - update count
            for (auto k = 0U; k < preamble_curr.size(); k++) {
              //find which timeslot overlapped
              auto it = std::find(v.begin(), v.end(), preamble_curr[k]);
              if (it != v.end()) overlap_count[k]++;  //increase kth entry
            }
          }
        } else
          continue;
      }

      //find the maximum overlap count
      int max = *std::max_element(overlap_count.begin(), overlap_count.end());
      if (max < M - 1) {
        cout << " Max overlap: " << max << endl;
        return true;
      } else
        return false;
    }
  }
}

//

vector<int> SimObj::getData_PktOverlapTimes(int other_pkt, vector<int> curr) {
  //other pkt's  time slots
  // L+I+N bits preamble
  std::vector<int> pkt(L + I + N + 1);
  std::iota(std::begin(pkt), std::end(pkt), arr_times[other_pkt]);  //populate

  //get intersection - to check any overlap in time slots
  std::vector<int> v(L + I + N + 1);  //vector for storing intersection between ID (curr) and other_pkt

  auto it = std::set_intersection(curr.begin(), curr.end(), pkt.begin(), pkt.end(), v.begin());

  v.resize(it - v.begin());

  return v;
}

//data decoding
bool SimObj::isDataDecoded(int pkt_idx) {
  //************************************************
  //current pkt's ID time slots
  std::vector<int> data_curr(N);                                                      // N bits data
  std::iota(std::begin(data_curr), std::end(data_curr), arr_times[pkt_idx] + L + I);  //populate

  //print ID time-occupancy

  cout << "\nData of pkt " << pkt_idx << " spans: (";
  for (auto d : data_curr) cout << d << ", ";

  cout << ") time slots" << endl;

  vector<int> v;
  vector<int> overlap_count(L);

  for (int j = 0; j < pkt_idx; j++) {
    if (j == pkt_idx) continue;
    if ((((pkt_idx > j)) && (arr_times[pkt_idx] - arr_times[j] < (N + I))) || ((pkt_idx < j) && (arr_times[j] - arr_times[pkt_idx] < (L + I)))) {
      //find overlapped time slots and increase count
      cout << " pkt # that overlapped ID " << j << endl;
      v = getData_PktOverlapTimes(j, data_curr);
      if (v.size() != 0) {  //inference - update count
        for (auto k = 0U; k < data_curr.size(); k++) {
          //find which timeslot overlapped
          auto it = std::find(v.begin(), v.end(), data_curr[k]);
          if (it != v.end()) overlap_count[k]++;  //increase kth entry
        }
      }
    } else
      continue;
  }

  //find the maximum overlap count
  int max = *std::max_element(overlap_count.begin(), overlap_count.end());
  if (max < P) {
    cout << " Max overlap for ID and other pkts: " << max << endl;
    return true;
  } else
    return false;
}
//ID decoding

bool SimObj::isIDDecoded(int pkt_idx) {
  //current pkt's ID time slots
  std::vector<int> id_curr(I);                                                // I bits ID
  std::iota(std::begin(id_curr), std::end(id_curr), arr_times[pkt_idx] + L);  //populate

  //print ID time-occupancy

  cout << "\nID of pkt " << pkt_idx << " spans: (";
  for (auto d : id_curr) cout << d << ", ";
  cout << ") time slots" << endl;

  vector<int> v;
  vector<int> overlap_count(L);

  for (int j = 0; j < pkt_idx; j++) {
    //if( arr_times[pkt_idx] - arr_times[j] < (N+I)){
    //find overlapped time slots and increase count
    //	    cout << " Prev pkt # that overlapped ID " << j << endl;
    v = getID_PktOverlapTimes(j, id_curr);
    //cout << v.size() << " " << pkt_idx << " " << j << endl;
    if (v.size() != 0) {  //interference - update count
      for (auto k = 0U; k < id_curr.size(); k++) {
        //find which timeslot overlapped
        auto it = std::find(v.begin(), v.end(), id_curr[k]);
        //increase kth entry
        if (it != v.end()) overlap_count[k]++;
      }
    }
  }

  for (int j = arr_times.size() - 1; j > pkt_idx; j--) {
    //if( (arr_times[j] - arr_times[pkt_idx]) < (L+I)){
    //find overlapped time slots and increase count
    //cout << " Nxt pkt # that overlapped ID " << j << endl;
    v = getID_PktOverlapTimes(j, id_curr);
    if (v.size() != 0) {  //inference - update count
      for (auto k = 0U; k < id_curr.size(); k++) {
        //find which timeslot overlapped
        auto it = std::find(v.begin(), v.end(), id_curr[k]);
        //increase kth entry
        if (it != v.end()) overlap_count[k]++;
      }
    }
  }

  //find the maximum overlap count
  int max = *std::max_element(overlap_count.begin(), overlap_count.end());
  cout << " Max overlap for ID and other pkts: " << max << endl;
  return (max < Q);

  //*************************************************
}

/* Run the simulation - it is a 3 step process according to the assignment:
 *   1. Detector detects the preamble iff:
 *     - no other preamble overlaps, or
 *     - no more than (M-1) ID/Data bits from other pkts should interfere at any bit of preamble at any instance OUTPUT: > if preamble is detected succesfully, the pkt is decoded (by decoder) in the following 2 steps, else it is considered as F in output file and the simulator process the next pkt
 *   2. Decoder tries to decode the ID part of the Pkt and succesfully do so, iff
 *									- if ID portion of the packet interferes (time overlaps) with no more than (Q-1) other packet preamble, ID, or data portions (even if these packets are not detected).
 *								OUTPUT: > if ID is decoded succesfully, the data part is decoded (by decoder) in the following step, else it is considered as D in output file and the simulator process the next pkt
 *							3. Decoder tries to decode the Data part of the Pkt and succesfully do so, iff
 *									- if Data portion of the packet interferes (time overlaps) with no more than (P-1) other packet preamble, ID or data portions (even if these packets are not detected).
 *								OUTPUT: > if Data is decoded succesfully, it is considered as S in output file, else it is considered as I in output file. Detection and decoding is done for this Pkt and next pkt is processed then
*/

void SimObj::runSimulation() {
  pkt_status = vector<char>{};

  //detect and decode each pkt according to arrival time and other parameters

  for (auto i = 0U; i < arr_times.size(); i++) {  //scan through each pkt

    if (isDetected(i)) {  //i-th pkt is detected successfully  //STEP 1 - PASS
      cout << " pkt # " << i << " detected " << endl;
      if (isIDDecoded(i)) {  //ID of i-th pkt decoded correctly //STEP 2 - PASS
        cout << " pkt # " << i << " ID decoded " << endl;
        if (isDataDecoded(i))
          pkt_status.push_back('S');  //data of i-th pkt decoded correctly: STEP 3 - PASS
        else
          pkt_status.push_back('I');  // data decoding of i-th pkt failed: STEP 3 - FAIL
      } else {                        //ID of ith pkt was not decoded - STEP 2: FAIL
        cout << " pkt # " << i << " ID was not decoded " << endl;
        pkt_status.push_back('D');
      }
    } else {  //ith pkt is not even detected by the decoder - this pkt is labelled F //STEP 1 - FAIL
      cout << " pkt # " << i << " not detected " << endl;
      pkt_status.push_back('F');
    }
  }
}

void SimObj::write_to_output() {
  ofstream ofs;
  ofs.open(out_fname);
  for (auto i = 0U; i < pkt_status.size(); i++) {
    cout << pkt_status[i] << "\t" << (i + 1) << endl;
    ofs << pkt_status[i] << endl;
  }
  ofs.close();
}
