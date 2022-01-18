#include <iostream>
#include "StrBlob.h"
using namespace std;
int main1222() {
	const StrBlob s({"a","b","c"});
	auto b = s.cbegin();
	auto e = s.cend();
	while (b != e) {
		cout << b.deref() << endl;
		b.incr();
	}
	return 0;
}