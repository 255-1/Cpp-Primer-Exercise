#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main1034() {

	vector<string> vs{ "asf","zxc","cnh" };
	for (auto it = vs.crbegin(); it != vs.crend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}