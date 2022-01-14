#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;


int main1112() {
	ifstream ifs("input1112.txt");
	string word;
	int num;
	vector<pair<string, int>> vpsi;
	while (ifs >> word) {
		ifs >> num;
		vpsi.push_back(make_pair(word, num));
	}
	for (const auto e : vpsi) {
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}
