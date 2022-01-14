#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
using namespace placeholders;
bool check_size1024(const string& s, int target) {
	return s.size() < target;
}

int main1024() {
	string s("asdd");
	vector<int> vi{ 0,1,2,3,4,5,6,7 };
	auto wc = find_if(vi.begin(), vi.end(),
		bind(check_size1024, s, _1));
	cout << *wc << endl;

	return 0;
}