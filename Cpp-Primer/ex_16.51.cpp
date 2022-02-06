#include <iostream>
using namespace std;
template <typename T, typename... Args>
void foo(const T& t, const Args&... rest) {
	cout << sizeof...(Args) << endl;
	cout << sizeof...(rest) << endl;
}

int main1651()
{
	int i = 0;
	double d = 3.14;
	string s = "how now";
	foo(i, s, 42, d);
	foo(d, s);
	foo("hi");
	return 0;
}