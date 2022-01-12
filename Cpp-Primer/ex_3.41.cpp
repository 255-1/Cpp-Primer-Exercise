#include <iostream>
#include <vector>

using namespace std;

int main341() {

	int arr[5] = { 0, 1, 2, 3, 4 };
	vector<int> iv(begin(arr), end(arr));

	for (auto e : iv) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}