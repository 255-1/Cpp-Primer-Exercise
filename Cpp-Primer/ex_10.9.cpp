#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(vector<string>& vs) {
	for (auto e : vs)cout << e << " ";
	cout << endl;
	sort(vs.begin(), vs.end());
	for (auto e : vs)cout << e << " ";
	cout << endl;
	auto end_unique = unique(vs.begin(), vs.end());
	vs.erase(end_unique, vs.end());
	for (auto e : vs)cout << e << " ";
	cout << endl;
}

int main109() {
	vector<string> vs{ "the","quick","red","fox","jumps",
	"over","the","slow","red","turtle" };
	elimDups(vs);

	return 0;
}