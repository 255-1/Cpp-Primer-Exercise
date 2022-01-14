#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main1029() {

	ifstream ifs("input.txt");
	vector<string> vs;
	istream_iterator<string> iis(ifs), eof;
	while (iis != eof) {
		vs.push_back(*iis++);
	}

	copy(vs.begin(), vs.end(), ostream_iterator<string>(cout," "));

	return 0;
}