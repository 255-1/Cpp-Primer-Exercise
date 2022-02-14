#include <iostream>
#include "Screen.h"
using namespace std;

int main1912()
{
	const Screen<10,10>::pos Screen<10,10>::*p = &Screen<10,10>::cursor;

	Screen<10, 10> s;

	auto res = s.*p;
	cout << res << endl;
	return 0;
}