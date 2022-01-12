#include <iostream>

using namespace std;

int func621(const int lhs, const int const *rhs) {
	return lhs > *rhs ? lhs : *rhs;
}

int main621() {
	int a = 32, * b = &a;
	int c = 42;
	cout << func621(22,b) <<endl;
	return 0;
}