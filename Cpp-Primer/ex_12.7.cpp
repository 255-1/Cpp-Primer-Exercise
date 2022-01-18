#include <vector>
#include <iostream>

using namespace std;
using Ptr = shared_ptr<vector<int>>;

Ptr func127_1() {
	return make_shared<vector<int>>();
}

void func127_2(Ptr p) {
	int num;
	while (cin >> num) {
		p->push_back(num);
	}
}
void func127_3(Ptr p) {
	for (auto e : *p) {
		cout << e << " ";
	}
	cout << endl;
	p->clear();
}

int main127() {
	Ptr p = func127_1();
	func127_2(p);
	func127_3(p);

	return 0;
}