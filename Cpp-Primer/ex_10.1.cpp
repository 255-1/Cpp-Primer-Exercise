#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main101() {

	vector<int> vi{ 0,1,2,3,4,4,3,2,2,2,2,1,1 };
	cout << count(vi.begin(), vi.end(), 2) << endl;

	return 0;
}