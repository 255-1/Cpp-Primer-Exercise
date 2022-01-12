#include <iostream>
#include <string>
using namespace std;

const string& func944(string& s,
	const string& oldVal,
	const string& newVal) {

	for (auto it = s.begin(); it <= s.end() - oldVal.size();) {
		if (oldVal == string(it, it + oldVal.size())) {
			s.replace(it, it + oldVal.size(),newVal);
			it += newVal.size();
		}
		else {
			++it;
		}
	}

	return s;
}

int main944() {

	string s("thothru");
	cout << func944(s, "tho", "though") << endl;
	cout << func944(s, "thru", "through") << endl;


	return 0;
}