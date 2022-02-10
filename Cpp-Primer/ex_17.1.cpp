#include <iostream>
#include <tuple>
using namespace std;

int main171()
{
	tuple<int, int, int> threeInt(10, 20, 30);
	auto threeInt2 = make_tuple(10, 20, 30);

	cout << get<0>(threeInt) << endl;
	cout << get<1>(threeInt) << endl;
	cout << get<2>(threeInt) << endl;
	return 0;
}