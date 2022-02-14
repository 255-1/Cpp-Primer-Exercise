#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main1913()
{
	const string Sales_data::* p = &Sales_data::bookNo;
	Sales_data s("a",1,1);
	auto res = s.*p;
	cout << res << endl;

	return 0;
}