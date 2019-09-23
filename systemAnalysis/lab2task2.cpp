#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct studentRecord {
  string firstName;
  string lastName;
  char studyLevel;
  char sex;
  unsigned ID;
  double gpa;
};

studentRecord *readRecordFile(string fileName, unsigned &counter) {
  studentRecord *recordArray;
  ifstream reader(fileName);
  if (!reader) {
    cout << "Error opening file: " << fileName << endl;
    exit(1);
  } else {
    reader >> counter;
    recordArray = new studentRecord[counter];
    for (auto i = 0U; i < counter; i++) {
      reader >> recordArray[i].firstName;
      reader >> recordArray[i].lastName;
      reader >> recordArray[i].gpa;
      reader >> recordArray[i].studyLevel;
      reader >> recordArray[i].sex;
      reader >> recordArray[i].ID;
    }
  }
  reader.close();
  return recordArray;
}

int main() {
  auto femaleCount = 0U, underGradCount = 0U, arraySize = 0U;
  auto records = readRecordFile("student.txt", arraySize);
  for (auto i = 0U; i < arraySize; i++) {
    if (records[i].sex == 'F')
      femaleCount++;
    if (records[i].studyLevel == 'U')
      underGradCount++;
  }
  cout << "There are " << femaleCount << " female students." << endl;
  cout << "There are " << underGradCount << " undergrad students." << endl;
  return 0;
}
