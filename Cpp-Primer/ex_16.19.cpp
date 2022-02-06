#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print1619(const T& t) {
	for (typename T::size_type i = 0; i != t.size(); ++i) {
		cout << t[i] << endl;
	}
}
int main1619()
{
	vector<int> v{ 1,2,3,4,5 };
	vector<string> v2{ "a","aa" };
	
	print1619(v);
	print1619(v2);

	return 0;
}