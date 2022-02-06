#include <iostream>
#include <vector>
#include <list>
#include <xutility>
using namespace std;

template <typename Iter, typename Target_Type>
inline Iter find164(const Iter& begin, const Iter& end, const Target_Type& target)
{
	Iter p = begin;
	while (p != end && *p != target)
		++p;
	return p;
}
int main164()
{
	vector<int> vi{ 0,1,2,3,4,5 };
	cout << *find164(vi.begin(), vi.end(), 3) << endl;
	list<int> li{ 0,1,2,3,4,5 };
	cout << *find164(vi.begin(), vi.end(), 3);
	return 0;
}