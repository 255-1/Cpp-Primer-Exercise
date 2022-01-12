#include <iostream>

using namespace std;

int main343() {

	int a[3][4], cnt=1;
	for (int (&e)[4] : a) {
		for (int& f : e) {
			f = cnt;
			++cnt;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int(*p)[4] = a; p != a + 3; ++p) {
		for (int* q = *p; q != *p + 4; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}

	return 0;
}