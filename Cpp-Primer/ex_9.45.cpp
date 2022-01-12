#include <string>
#include <iostream>
using namespace std;

const string& func945(string& s, const string& prefix, const string& suffix) {

	s.insert(s.begin(), prefix.begin(), prefix.end());
	s.append(suffix.begin(), suffix.end());
	return s;
}

int main945() {
	string s("zzj");
	cout << func945(s, "Mr.", "III") << endl;


	return 0;
}