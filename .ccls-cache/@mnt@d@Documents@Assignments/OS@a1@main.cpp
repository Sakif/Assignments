#include "main.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc == 2) {
		/* when 1 argument is passed */
		string arg = argv[1];
		if (arg.compare("-randomize") == 0) {
			/* check if the argument is -randomize */
			srandom(time(NULL));
		} else {
			/* the argument is to change the number of days to simulate */
			days_to_simulate = atoi(argv[1]);
		}
	} else if (argc < 4) {
		/* when there are 2+ arguments, first argument is to change the number of days to simulate */
		days_to_simulate = atoi(argv[1]);
		string arg = argv[2];
		if (arg.compare("-randomize") == 0) {
			/* the second argument is for -randomize */
			srandom(time(NULL));
		}
	} else {
		cout << "Invalid number of arguments were passed." << endl;
	}
	return 0;
}
