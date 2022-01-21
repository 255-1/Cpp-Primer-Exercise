#include <iostream>
#include <vector>
#include "String.h"

using namespace std;

int main1348() {
	vector<String> vs;
	String s1("a");
	for (int i = 0; i < 10; ++i) {
		cout << "push back " << (i + 1) << endl;
		vs.push_back(s1);
	}
	return 0;
}