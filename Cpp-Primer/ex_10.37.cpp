#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main1037() {
	vector<int> vi{ 0,1,2,3,4,5,6,7,8,9 };
	list<int> li;
	copy(vi.crbegin() + 3, vi.crbegin() + 8, back_inserter(li));
	copy(li.cbegin(), li.cend(), ostream_iterator<int>(cout, " "));

	return 0;
}