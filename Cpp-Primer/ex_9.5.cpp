#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int>::const_iterator func95(vector<int>::const_iterator beg,
	vector<int>::const_iterator end,
	int target) {
	while (beg != end) {
		if (*beg == target) {
			return beg;
		}
		++beg;
	}
	return end;
}

int main95() {

	vector<int> vi{ 0,1,2,3,4,5,6,7,8,9 };
	cout << *func95(vi.begin()+1, vi.begin()+5, 8) << endl;

	return 0;
}