#include <vector>
#include <iostream>

using namespace std;

vector<int>* func126_1() {
	return new vector<int>();
}

void func126_2(vector<int>* p) {
	int num;
	while (cin >> num) {
		p->push_back(num);
	}
}
void func126_3(vector<int>* p) {
	for (auto e : *p) {
		cout << e << " ";
	}
	cout << endl;
	delete p;
}

int main126() {
	vector<int>* p = func126_1();
	func126_2(p);
	func126_3(p);

	return 0;
}