#include <iostream>
#include <map>
using namespace std;

int main113() {

	map<string, size_t> mss;
	string word;
	while (cin >> word) {
		++mss[word];
	}
	for (const auto& e : mss) {
		cout << e.first << " " << e.second << endl;
	}

	return 0;
}