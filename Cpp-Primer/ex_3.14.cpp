#include <iostream>
#include <vector>

using namespace std;

int main314()
{
	int num;
	vector<int> iv;
	while (cin >> num) {
		iv.push_back(num);
	}

	for (const auto e : iv) {
		cout << e << endl;
	}

	return 0;
}