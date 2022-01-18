#include <iostream>
#include <fstream>
#include "StrBlob.h"

using namespace std;

int main1220() {

	StrBlob s;
	ifstream ifs("input1220.txt");
	string word;
	while (ifs >> word) {
		s.push_back(word);
	}
	auto b = s.begin();
	auto e = s.end();
	while (b!=e) {
		cout << b.deref() << endl;
		b.incr();
	}
	return 0;
}