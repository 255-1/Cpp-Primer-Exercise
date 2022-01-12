#include <iostream>

using namespace std;

int main335() {

	int a[5];
	for (auto e : a) {
		cout << e << " ";
	}
	cout << endl;

	int* p = begin(a);
	while (p != end(a)) {
		*p++ = 0;
	}
	for (auto e : a) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}