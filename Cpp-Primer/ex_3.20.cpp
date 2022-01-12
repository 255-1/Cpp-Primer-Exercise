#include <iostream>
#include <vector>
using namespace std;

int main320() {

	int num;
	vector<int> iv;
	while (cin >> num)
	{
		iv.push_back(num);
	}

	for (int i = 0; i < iv.size()-1; ++i) {
		cout << iv[i] + iv[i + 1] << endl;
	}

	cout << "------------------" << endl;
	// If the vector has odd size, element in the middle will add to itself.
	auto size = (iv.size() + 1) / 2;

	for (int i = 0; i != size; ++i)
		cout << iv[i] + iv[iv.size() - i - 1] << " ";
	cout << endl;

	return 0;
}