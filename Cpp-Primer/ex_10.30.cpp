#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main1030() {
	istream_iterator<int> iii(cin), eof;
	vector<int> vi;
	while (iii != eof) {
		vi.push_back(*iii++);
	}
	sort(vi.begin(), vi.end());
	//copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "));


	return 0;
}