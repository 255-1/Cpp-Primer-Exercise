#include <iostream>
#include <vector>
using namespace std;

int main332() {

	int arr[10], arr2[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; ++i) {
		arr2[i] = arr[i];
	}

	for (int e : arr2) {
		cout << e << " ";
	}
	cout << endl;

	//使用vector实现类似的功能
	vector<int> iv;
	for (int i = 0; i < 10; ++i) {
		iv.push_back(i);
	}
	vector<int> iv2 = iv;
	for (int e : iv2) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}