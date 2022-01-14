#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool func1013(const string& s) {
	return s.size() >= 5;
}

int main1013() {
	vector<string> vs{ "sadas","asd","asdasf","zxcvz" };
	auto it = partition(vs.begin(), vs.end(), func1013);
	for (auto i = vs.begin(); i != it; ++i) {
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}