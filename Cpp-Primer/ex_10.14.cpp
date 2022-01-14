#include <iostream>
using namespace std;

int main1014() {

	auto f = [](int a, int b)->int {return a + b; };
	cout << f(3, 4) << endl;
	return 0;
}