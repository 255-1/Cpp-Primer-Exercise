#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool func1022(const string& s, size_t sz) {
	return s.size() <= sz;
}

int main1022() {

	vector<string> vs{ "the","quick","red","fox","jumps",
	"over","the","slow","red","turtle" };
	auto f = bind(func1022, _1, 5);
	auto it = partition(vs.begin(), vs.end(), f);
	for (auto i = vs.begin(); i != it; ++i) {
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}