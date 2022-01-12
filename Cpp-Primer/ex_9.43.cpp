#include <iostream>
#include <string>

using namespace std;

const string& func943(string& s,
	const string& oldVal,
	const string& newVal) {
	
	for (auto it = s.begin(); it <= s.end()-oldVal.size();) {
		if (oldVal == string(it, it+oldVal.size())) {
			it = s.erase(it, it+oldVal.size());
			it = s.insert(it, newVal.begin(), newVal.end());
			it += newVal.size();
		}
		else {
			++it;
		}
	}
	
	return s;
}

int main943() {

	string s("thothru");
	cout << func943(s, "tho", "though") << endl;
	cout << func943(s, "thru", "through") << endl;


	return 0;
}