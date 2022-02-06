#include <iostream>
#include <vector>
using namespace std;

template <typename T> void g(T&& val) {
	vector<T> v;
}

int main1645() {

	//g(42);
	int i = 42;
	//g(i);

	return 0;
}