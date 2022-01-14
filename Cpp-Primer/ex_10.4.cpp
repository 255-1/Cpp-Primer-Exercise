#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main104() {

	vector<double> vd{ 0.1,0.2,0.3,0.5 };
	cout << accumulate(vd.cbegin(), vd.cend(), 0.0) << endl;

	return 0;
}