#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool have_prefix(vector<int>& v1, vector<int>& v2) {
	if (v1.size() > v2.size()) {
		return have_prefix(v2, v1);
	}
	//假设v1的长度小于v2
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

int main517() {

	vector<int> v1{ 0,1,1,1 };
	vector<int> v2{ 0,1,1,2,3,5,8 };

	cout << (have_prefix(v2, v1) ? "yes" : "no") << endl;

	return 0;
}