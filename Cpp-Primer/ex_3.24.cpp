#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main324() {

	//µü´úÆ÷ÖØĞ´3.20
	vector<int> iv{ 0,1,2,3,4,5,6 };
	for (auto it = iv.begin(); it != iv.end()-1; ++it) {
		cout << *it + *(it + 1) << " ";
	}
	cout << endl;

	for (auto l = iv.begin(), r = iv.end() - 1;
		l <= r;
		++l, --r) {
		cout << *l + *r << " ";
	}
	cout << endl;


	return 0;
}