#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main1228() {
	ifstream ifs("input1228.txt");
	vector<string> vs;
	map<string, set<int>> mss;
	string sentence;
	int line = 1;
	while (getline(ifs, sentence)) {
		vs.push_back(sentence);
		string word;
		stringstream ss(sentence);
		while (ss >> word) {
			mss[word].insert(line);
		}
		++line;
	}
	cout << "Input the element to look up: \n";
	string input;
	while (cin >> input) {
		if (mss.find(input) == mss.end()) {
			cout << "empty" << endl;
		}
		auto res = mss[input];
		cout << input << "occurs " << res.size() << " times" << endl;
		for (auto e : res) {
			cout << "(line " << e << ") " << vs[e - 1] << endl;
		}
	}

	//for (auto it = mss.cbegin(); it != mss.cend(); ++it) {
	//	cout << it->first << " ";
	//	for (auto e : it->second) {
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}

	return 0;
}