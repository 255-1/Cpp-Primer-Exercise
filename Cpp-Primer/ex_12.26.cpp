#include <memory>
#include <iostream>
#include <string>
using namespace std;

int main1226() {
	size_t n = 3;
	allocator<string> alloc;
	string* const p = alloc.allocate(n);
	string s;
	string* q = p;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	while (q != p) {
		cout << *--q << endl;
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
	return 0;
}