#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int main103() {
	vector<int> vi{ 0,1,2,3,4 };
	cout << accumulate(vi.begin(), vi.end(), 0) << endl;


	return 0;
}