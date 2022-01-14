#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main1036() {
	list<int> li{ 0,1,2,3,4,5,6,0,7,8,9 };
	auto it = find(li.crbegin(), li.crend(), 0);
	auto base = it.base();
	while (base != li.end()) {
		cout << *base++ << endl;
	}

	return 0;
}