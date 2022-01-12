#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

int main912() {

	list<int> li{ 1,2,3,4,5,6 };
	vector<int> vi{ 7,8,9,10 };
	vector<double> vd(li.begin(), li.end());
	vector<double> vd2(vi.begin(), vi.end());

	for (auto e : vd) {
		cout << e << " ";
	}
	cout << endl;
	for (auto e : vd2) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}