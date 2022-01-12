#include <string>
#include <deque>
#include <iterator>
#include <iostream>
using namespace std;

int main918() {

	deque<string> ds;
	string word;
	while (cin >> word) {
		ds.emplace_back(word);
	}

	for (auto it = ds.cbegin(); it != ds.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}