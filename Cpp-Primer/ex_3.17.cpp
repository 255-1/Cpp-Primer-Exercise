#include <iostream>
#include <vector>

using namespace std;

int main317()
{
	string word;
	vector<string> vs;
	while (cin >> word) {
		vs.push_back(word);
	}

	for (auto& word : vs) {
		for (auto& c : word) {
			c = toupper(c);
		}
	}

	for (auto e : vs) {
		cout << e << endl;
	}

	return 0;
}