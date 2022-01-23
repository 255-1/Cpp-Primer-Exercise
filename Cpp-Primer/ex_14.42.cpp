#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
using namespace placeholders;
int main1442()
{
	vector<int> ivec{ 0,100,1000,10000,12321 };
	vector<string> svec{ "pooh","asd" };
	cout << count_if(ivec.begin(), ivec.end(), bind(greater<int>(), _1, 1024)) << endl;
	cout << *find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), _1, "pooh"))<<endl;
	transform(ivec.begin(), ivec.end(), ivec.begin(),bind(multiplies<int>(),_1, 2));
	copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));
	return 0;
}