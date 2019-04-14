#include <iostream>
#include <fstream>
#include "interfaces.h"

using namespace std;
using namespace machines;

int main(int argc, char *argv[]) {

	if (argc != 3) {
		cout << "Usage: lab_oop <input file> <output file>" << endl;
		return 1;
	}

	ifstream inp(argv[1]);
	ofstream out(argv[2]);

	if (!inp.is_open()) {
		cout << "Could not to open input file!\n";
		return 1;
	}

	if (!out.is_open()) {
		cout << "Could not to open output file!\n";
		return 1;
	}

	cout << "Start.\n";

	RingList container;
	cout << "Reading input\n";
	container.fill(inp);
	cout << "Writing information\n";
	container.out(out);
	container.fill(inp);
	container.multimethod(out);
	cout << "Clearing list\n";
	container.clear();
	container.out(out);

	return 0;
}