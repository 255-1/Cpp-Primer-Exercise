#include <iostream>

using namespace std;

void ex6_6(int i) {
	int a = 1;
	static int b = 0;
	cout << "�β� i:" << i << endl;
	cout << "�ֲ����� a: " << a << endl;
	cout << "�ֲ���̬���� b: " << b << endl;
	++b;
}

int main66() {

	for (int i = 0; i < 10; ++i) {
		ex6_6(5);
	}


	return 0;
}