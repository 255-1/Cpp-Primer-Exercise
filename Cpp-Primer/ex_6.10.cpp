#include <iostream>

void swap610(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main610() {

	int a = 10, b = 5;
	std::cout << a << " " << b << std::endl;
	swap610(&a, &b);
	std::cout << a << " " << b << std::endl;

	return 0;
}