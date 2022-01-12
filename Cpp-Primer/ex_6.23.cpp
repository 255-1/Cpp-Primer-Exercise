#include <iostream>

using namespace std;

void print(int i) {
	cout << i << endl;
}

void print(const int * beg, const int*end) {
	while (beg!=end) {
		cout << *beg++ << endl;
	}
}

void print(const int(&arr)[2]) {
	for (int i = 0; i < 2; ++i) {
		cout << arr[i] << endl;
	}
}

int main623() {

	int i = 0, j[2] = { 0,1 };
	print(i);
	print(begin(j), end(j));
	print(j);
	return 0;
}