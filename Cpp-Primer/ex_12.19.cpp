#include <iostream>
#include "StrBlob.h"
#include <string>
#include <initializer_list>

using namespace std;
int main1219() {
	StrBlob s({"a","b","c","d"});
	cout << s.front() << endl;
	StrBlobPtr p = s.begin();
	cout << p.deref() << endl;
	p.incr();
	cout << p.deref() << endl;

	return 0;
}