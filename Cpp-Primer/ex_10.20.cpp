#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main1020() {

	vector<string> vs{ "the","quick","red","fox","jumps",
	"over","the","slow","red","turtle" };

	cout << count_if(vs.begin(), vs.end(),
		[](const string& s) {
			return s.size() >= 6;
		});
	return 0;
}