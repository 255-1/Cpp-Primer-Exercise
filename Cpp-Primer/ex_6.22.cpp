#include <iostream>

using namespace std;

void func622(int*& lhs, int *& rhs) {
	int* t = lhs;
	lhs = rhs;
	rhs = t;
}

int main622() {
	int a = 42, b = 32;
	int* p1 = &a, * p2 = &b;
	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;
	func622(p1, p2);
	cout << "*p1 = " << *p1 << endl;
	cout << "*p2 = " << *p2 << endl;
	return 0;
}