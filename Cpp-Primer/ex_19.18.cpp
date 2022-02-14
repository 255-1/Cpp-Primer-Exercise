#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using namespace placeholders;
int main1918() {
	function<bool(const string&)> fcn = &string::empty;
	vector<string> vs{ "a", "b", "c", "", "" };
	
	cout << count_if(vs.begin(), vs.end(), bind(&string::empty, _1)) << endl;
	cout << count_if(vs.begin(), vs.end(), fcn) << endl;
	cout << count_if(vs.begin(), vs.end(), mem_fn(&string::empty)) << endl;
}