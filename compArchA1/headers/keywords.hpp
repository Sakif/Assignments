#include "splitString.hpp"
#include <fstream>
#include <string>

using namespace std;

class keywords{
	public:
	keywords(string="isa.csv");
};

keywords::keywords(string filename){
	ifstream kwd(filename);
	
	kwd.close();
}