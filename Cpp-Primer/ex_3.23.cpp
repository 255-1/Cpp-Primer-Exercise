#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main323() {

	vector<int> iv = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto it = iv.begin(); it != iv.end(); ++it) {
		*it *= 2;
	}
	for (auto it = iv.begin(); it != iv.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}