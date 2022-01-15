#include <iostream>
#include <map>
#include <string>
using namespace std;

int main1131() {

	using authorName = string;
	using book = string;
	multimap<authorName, book> mab{ {"a","a"},
		{"a","b"},{"a","c"},{"b","d"},{"e","e"} };
	multimap<authorName, book>::iterator it = mab.find("f");
	size_t count = mab.count("f");
	while (count) {
		mab.erase(it++);
		--count;
	}
	for (auto e : mab) cout << e.first << " " << e.second << endl;
	return 0;
}