#include <iostream>
#include <vector>
using namespace std;
int func654(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main654() {

	vector<int(*)(int, int)> v{ add,subtract,multiply,divide };
	for (auto e : v) {
		cout << e(2, 2) << endl;
	}


	return 0;
}