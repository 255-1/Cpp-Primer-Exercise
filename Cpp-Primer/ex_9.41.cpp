#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main941() {

	vector<char> vc{ 'a','b','c' };
	string s(vc.begin(), vc.end());
	cout << s << endl;

	return 0;
}