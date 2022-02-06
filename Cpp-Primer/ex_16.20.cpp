#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print1620(const T& t) {
	for (typename T::const_iterator it = t.begin();
		it != t.end();
		++it) {
		cout << *it << endl;
	}
}
int main1620()
{
	vector<int> v{ 1,2,3,4,5 };
	vector<string> v2{ "a","aa" };

	print1620(v);
	print1620(v2);

	return 0;
}