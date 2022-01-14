#include <vector>
#include <iostream>
using namespace std;

int main106() {

	vector<int> vi(10, 20);
	for (auto e : vi) cout << e << " ";
	cout << endl;
	fill_n(vi.begin(), vi.size(), 0);
	for (auto e : vi) cout << e << " ";
	cout << endl;

	return 0;
}