#include <iostream>

using namespace std;

bool test616(const string& s) {
	return s.empty();
}

int main616() {

	string s = "Hello";
	test616(s);
	test616("Hello");
	return 0;
}