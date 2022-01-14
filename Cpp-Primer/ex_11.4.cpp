#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

auto strip(string& str)->string const& {
	for (auto& ch : str) {
		ch = tolower(ch);
	}
	str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
	return str;
}

int main114() {

	map<string, size_t> mss;
	string word;
	while (cin >> word) {
		++mss[strip(word)];
	}
	for (const auto& e : mss) {
		cout << e.first << " " << e.second << endl;
	}

	return 0;
}