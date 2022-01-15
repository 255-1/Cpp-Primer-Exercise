#include <unordered_map>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main1138() {
	//wordCounting
	//unordered_map<string, size_t> umsi;
	//string word;
	//while (cin >> word) {
	//	auto ret = umsi.insert(make_pair(word, 1));
	//	if (ret.second == false)
	//		++ret.first->second;
	//}
	//for (auto e : umsi) {
	//	cout << e.first << " " << e.second << endl;
	//}

	//word trans
	ifstream ifs_map("input1133_map.txt"), ifs_content("input1133_input.txt");
	unordered_map<string, string> trans_map;
	for (string key, value; ifs_map >> key && getline(ifs_map, value);)
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
	for (string text, word; getline(ifs_content, text);
		cout << endl) {
		for (istringstream iss(text); iss >> word;) {
			auto map_it = trans_map.find(word);
			cout << (map_it == trans_map.cend() ? word : map_it->second) << " ";
		}
		
	}

	return 0;
}