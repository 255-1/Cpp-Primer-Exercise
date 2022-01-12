#include <iostream>

using namespace std;

void reset(int& i) {
	i = 0;
}

int main611() {

	int a = 10;
	cout << "a: " << a << endl;
	reset(a);
	cout << "a: " << a << endl;


	return 0;
}