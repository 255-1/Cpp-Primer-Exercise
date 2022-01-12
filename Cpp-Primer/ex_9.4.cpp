#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

bool func94(vector<int>::const_iterator beg,
			vector<int>::const_iterator end,
			int target) {
	while (beg != end) {
		if (*beg == target) {
			return true;
		}
		++beg;
	}
	return false;
}

int main94() {
	vector<int> vi{ 0,1,2,3,4,5,6,7,8,9 };
	cout << func94(vi.begin(), vi.end(), 10) << endl;

	return 0;
}