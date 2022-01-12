#include <list>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main914() {

	list<const char*> lcp{"aaa","bbb"};
	vector<string> vs(lcp.begin(), lcp.end());
	for (auto e : vs) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}