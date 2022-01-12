#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main810() {
	ifstream ifs("input.txt");
	vector<string> vs;
	string s;
	while (getline(ifs, s)) {
		vs.push_back(s);
	}

	for (auto s : vs) {
		istringstream iss(s);
		string tmp;
		while (iss>>tmp) {
			cout << tmp << endl;
		}
	}

	return 0;
}