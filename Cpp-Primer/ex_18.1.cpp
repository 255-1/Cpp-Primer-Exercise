#include <iostream>
using namespace std;

int main181()
{
	range_error r("error");
	//throw r;
	exception* p = &r;
	throw p;
	return 0;
}