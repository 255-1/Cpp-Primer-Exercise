#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main315() {

	string s;
	vector<string> vs;

	while (cin >> s) {
		vs.push_back(s);
	}
	
	for (const auto e : vs) {
		cout << e << endl;
	}
	
	return 0;
}