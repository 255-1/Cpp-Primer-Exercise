#include <iostream>

using namespace std;

void swap612(int& lhs, int& rhs) {
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int main612() {
	int a = 10, b = 5;
	cout << "a: " << a << " b: " << b << endl;
	swap612(a, b);
	cout << "a: " << a << " b: " << b << endl;

	return 0;
}