#include <vector>
#include <iterator>
#include <map>
#include <string>
#include <iostream>

using namespace std;
auto strip(string& str)->string const&;
int main1120() {
	map<string, size_t> mss;
	string word;
	while (cin >> word) {
		auto ret = mss.insert({word, 1});
		if (!ret.second)
			++ret.first->second;
	}
	for (const auto& e : mss) {
		cout << e.first << " " << e.second << endl;
	}


	return 0;
}