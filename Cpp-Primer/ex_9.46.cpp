#include <iostream>
#include <string>

using namespace std;

string& func946(string& s, const string& pre, const string& suf) {
	s.insert(0, pre, 0, pre.size());
	s.insert(s.size(), suf, 0, suf.size());
	return s;
}

int main946() {

	string s("zzj");
	cout << func946(s, "Mr.", "Jr.") << endl;
	return 0;
}
