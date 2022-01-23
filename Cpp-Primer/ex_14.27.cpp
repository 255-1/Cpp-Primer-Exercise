#include "StrBlob.h"
#include <iostream>
using namespace std;

int main1427()
{
	StrBlob s({"a","b","c","d","e"});
	StrBlobPtr p(s);
	cout << p.deref() << endl;
	++p;
	cout << p.deref() << endl;
	auto c = p++;
	cout << c.deref() << endl;
	cout << p.deref() << endl;
	return 0;
}