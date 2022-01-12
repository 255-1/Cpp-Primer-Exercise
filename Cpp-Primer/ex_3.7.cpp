#include <iostream>

using namespace std;

int main37()
{
	string s("adasdasd");

	for (auto c : s) {
		c = 'X';
	}
	cout << s << endl;


	return 0;
}