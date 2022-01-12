#include <iostream>
#include <vector>

using namespace std;

int main421() {

	vector<int> iv{ 0,1,2,3,4,5,6,7,8,9 };
	for (auto& e : iv) {
		cout << ((e & 0x1) ? e*=2 : e )<< " ";
	}
	cout << endl;

	return 0;
}