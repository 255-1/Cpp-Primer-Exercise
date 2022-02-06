#include <iostream>
using namespace std;

template<typename T>
inline int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}

int main162()
{
	cout << (compare(1, 0) == -1 ? "lhs" :
		(compare(1, 0) == 1) ? "rhs" : 0) << endl;

	return 0;
}