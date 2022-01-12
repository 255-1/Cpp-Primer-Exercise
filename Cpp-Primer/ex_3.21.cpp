#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main321() {

	vector<string> vs;
	string word;
	while (cin >> word)
	{
		vs.push_back(word);
	}

	for (vector<string>::iterator it = vs.begin();
		it != vs.end();
		++it) {

		for (string::iterator it2 = it->begin();
			it2 != it->end();
			++it2) {
			*it2 = toupper(*it2);
		}

	}

	for (vector<string>::iterator it = vs.begin();
		it != vs.end();
		++it) {
		cout << *it << endl;
	}

	return 0;
}