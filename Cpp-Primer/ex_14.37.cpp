#include <iostream>
#include <algorithm>
#include <vector>
class Foo1437 {
public:
	bool operator()(const int a, const int b)
	{
		return a == b;
	}
};

class Foo1437_2 {//Ìæ»»´úÂë¸ü¼ò½à
	int value;
public:
	Foo1437_2(int target) :value(target) {}
	bool operator()(const int elem)
	{
		return elem == value;
	}
};
using namespace std;
int main1437()
{
	Foo1437 f;
	int target = 3;
	vector<int> vs{ 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 };
	replace_if(vs.begin(), vs.end(), 
		[target](int a) {Foo1437 f; return f(a, target); }, 2);
	copy(vs.begin(), vs.end(), ostream_iterator<int>(cout, " "));

	cout << endl;
	//test2
	replace_if(vs.begin(), vs.end(),
		Foo1437_2(2), 5);
	copy(vs.begin(), vs.end(), ostream_iterator<int>(cout, " "));
	return 0;
}