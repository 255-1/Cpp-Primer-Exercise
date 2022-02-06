#include <iostream>
#include "Sales_data.h"
using namespace std;

template<typename T>
inline int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}

int main163()
{
	Sales_data s1("s1", 1, 1.0);
	Sales_data s2("s2", 2, 2.0);
	//cout << compare(s1, s2) << endl;

	return 0;
}