#include <iostream>
#include <fstream>
#include "TextQuery2.h"
using namespace std;
void runQueries1233(ifstream& infile) {
	TextQuery2 tq(infile);
	cout << "enter word to look for" << endl;
	string s;
	while (cin >> s) {
		print2(cout, tq.query(s)) << endl;
	}
}

int main1233() {
	ifstream ifs("input1229.txt");
	runQueries1233(ifs);

	return 0;
}