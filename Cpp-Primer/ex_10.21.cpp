#include <iostream>
using namespace std;

int main1021() {
	int local = 5;
	auto f = [&]()->bool {
		while (local > 0)
			--local;
		return local == 0;
	};

	cout << f() << endl;

	return 0;
}