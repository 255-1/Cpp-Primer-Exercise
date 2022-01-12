#include <iostream>
#include <deque>
#include <list>
using namespace std;

int main920() {

	list<int> li{ 0,1,2,3,4,5,6,7,8,9 };
	deque<int> odd, even;
	for (auto it = li.cbegin(); it != li.cend(); ++it) {
		if (*it & 0x1) {
			odd.emplace_back(*it);
		}
		else {
			even.emplace_back(*it);
		}
	}

	for (auto e : odd) {
		cout << e << " ";
	}
	cout << endl;
	for (auto e : even) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}