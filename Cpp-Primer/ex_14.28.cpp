#include "StrBlob.h"
#include <iostream>
using namespace std;

int main1428()
{
	StrBlob a({"a","v","c","t"});
	StrBlobPtr s(a);
	cout << (s + 2).deref() << endl;


	return 0;
}