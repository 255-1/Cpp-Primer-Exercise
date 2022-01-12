#include <string>
#include <deque>
#include <iterator>
#include <iostream>
#include <list>
using namespace std;

int main919() {

	list<string> ds;
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