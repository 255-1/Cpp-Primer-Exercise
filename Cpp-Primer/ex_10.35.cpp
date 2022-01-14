#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main1035() {

	vector<string> vs{ "asf","zxc","cnh" };
	for (auto it = vs.cend()-1; true; --it) {
		if (it == vs.cbegin()) {
			cout << *it << endl;
			break;
		}
		cout << *it << endl;
	}

	return 0;
}