#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isShorter(const string& s1, const string& s2);
void elimDups2(vector<string>& vs) {
	sort(vs.begin(), vs.end());
	auto end_unique = unique(vs.begin(), vs.end());
	vs.erase(end_unique, vs.end());
}

//bool isShorter(const string& s1, const string& s2) {
//	return s1.size() < s2.size();
//}

int main1011() {
	vector<string> vs{ "the","quick","red","fox","jumps",
	"over","the","slow","red","turtle" };
	elimDups2(vs);
	stable_sort(vs.begin(), vs.end(), isShorter);
	for (const auto& s : vs) cout << s << " ";
	cout << endl;
	return 0;
}