#include <iostream>

using namespace std;

int main331() {

	int arr[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	for (int e : arr) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}