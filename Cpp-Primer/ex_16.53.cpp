#include <iostream>
using namespace std;

template <typename T>
ostream& print(ostream& os, const T& t) {
	return os << t;
}
template <typename T, typename...Args>
ostream& print(ostream& os, const T& t, const Args&... rest) {
	os << t << ", ";
	return print(os, rest...);
}


class Nooutput {
	int i;
};
int main1653()
{
	int i = 0;
	string s = "asd";
	double d = 3.14;
	print(cout, i, s, d);
	//test Nooutput
	//print(cout, Nooutput());

	return 0;
}