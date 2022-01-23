#include "StrBlob.h"
#include <iostream>
using namespace std;

int main1430()
{
	StrBlob a({ "a","aa","aaa","aaaa" });
	StrBlobPtr s(a);
	cout << *s << endl;
	cout << (s+2)->c_str() << endl;

	const StrBlob b({ "b","bb" });
	ConstStrBlobPtr c(b,1);
	cout << *c << endl;
	return 0;
}