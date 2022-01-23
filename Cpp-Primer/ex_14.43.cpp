#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
using namespace placeholders;
int main1443()
{
	int input = 1;
	modulus<int> mod;
	vector<int> ivec{ 2,4,6,8 };
	bool res =  any_of(ivec.begin(), 
		ivec.end(), 
		[&](int i) {return 0 != mod(i, input); }
	);

	std::cout << (res ? "不能全部整除" : "能全部整除") << endl;
	return 0;
}