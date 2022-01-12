#include <iostream>

using int_array = int[4];
using namespace std;

int main344() {

	int a[3][4], cnt = 1;
	for (int(&e)[4] : a) {
		for (int& f : e) {
			f = cnt;
			++cnt;
		}
	}

	//使用别名
	for (int_array* p = a; p != a + 3; ++p) {
		for (int* q = *p; q != *p + 4; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}

	return 0;
}