#include <iostream>
#include <fstream>
#include "TextQuery.h"
using namespace std;
void runQueries(ifstream& infile) {
	TextQuery tq(infile);
	cout << "enter word to look for" << endl;
	string s;
	while (cin>>s) {
		print(cout, tq.query(s)) << endl;
	}
}

int main1230() {
	ifstream ifs("input1229.txt");
	runQueries(ifs);

	return 0;
}