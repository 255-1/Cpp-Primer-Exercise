#include <iostream>
using namespace std;

int func1015(int a) {
	auto f = [a](int b) {
		return a + b;
	};
	return f(5);
}

int main1015() {

	cout << func1015(10);

	return 0;
}