#include <iostream>

using namespace std;

int ex67() {
	static int a = 0;
	return a++;
}

int main67() {

	for (int i = 0; i < 10; ++i) {
		cout << ex67() << endl;
	}

	return 0;
}