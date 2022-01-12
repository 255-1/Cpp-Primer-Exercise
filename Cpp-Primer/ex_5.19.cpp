#include <iostream>
#include <string>

using namespace std;

int main519() {

	string s1, s2;
	cout << "Input two strings to show the shorter one: " << endl;
	cin >> s1 >> s2;
	do {
		cout << (s1.size()<s2.size()?s1:s2) << endl;
		cout << "Input two strings to show the shorter one: " << endl;
	} while (cin >> s1 >> s2);

	return 0;
}