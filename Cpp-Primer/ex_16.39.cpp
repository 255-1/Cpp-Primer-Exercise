#include <iostream>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2) {
	if (v1 < v2) return -1;
	if (v2 < v1)return 1;
	return 0;
}

int main1639() 
{
	cout << compare<std::string>("aaa", "sss") << endl;

	return 0;
}