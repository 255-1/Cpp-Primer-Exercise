#include <iostream>

using namespace std;

int main345() {

	int a[3][4], cnt = 1;
	for (int(&e)[4] : a) {
		for (int& f : e) {
			f = cnt;
			++cnt;
		}
	}

	// π”√auto
	for (auto& e1 : a) {
		for (auto& e2 : e1) {
			cout << e2 << " ";
		}
		cout << endl;
	}

	return 0;
}