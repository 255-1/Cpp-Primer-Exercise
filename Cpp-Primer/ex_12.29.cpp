#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main1229() {
	ifstream ifs("input1229.txt");
	vector<string> vs;
	map<string, set<int>> mss;
	string sentence;
	int line = 1;
	while (getline(ifs, sentence)) {
		vs.push_back(sentence);
		stringstream ss(sentence);
		for (string text, word;
			ss >> text; 
			word.clear()) {
			remove_copy_if(text.begin(), text.end(),
				back_inserter(word), ispunct);
			mss[word].insert(line);
		}
		++line;
	}
	cout << "Input the element to look up: \n";
	string input;
	cin >> input;
	do {
		if (mss.find(input) == mss.end()) {
			cout << "empty" << endl;
		}
		auto res = mss[input];
		cout << input << "occurs " << res.size() << " times" << endl;
		for (auto e : res) {
			cout << "(line " << e << ") " << vs[e - 1] << endl;
		}
		cout << "Input the element to look up: \n";
	} while (cin >> input);

	return 0;
}