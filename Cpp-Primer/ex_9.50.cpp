#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main950() {

	vector<string> vs{ "456","124","132412" };
	int sum = 0;
	for (const string& e : vs) {
		sum += stoi(e);
	}
	cout << sum << endl;

	return 0;
}