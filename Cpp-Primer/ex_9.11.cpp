#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main911() {

	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3{ 1,2,3,4 };
	vector<int> v4(v3.begin(), v3.begin() + 2);
	vector<int> v5(10);
	vector<int> v6(10, 4);
	for (auto e : v3) {
		cout << e << " ";
	}
	cout << endl;
	for (auto e : v4) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}