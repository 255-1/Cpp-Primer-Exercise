#include <string>
#include <iostream>
using namespace std;

int main947() {

	string s("ab2c3d7R4E6");
	string numbers("1234567890");
	size_t pos=0;
	while ((pos = s.find_first_of(numbers,pos)) != string::npos) {
		cout << s[pos] << " ";
		++pos;
	}
	cout << endl;
	pos = 0;
	while ((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
		cout << s[pos] << " ";
		++pos;
	}
	cout << endl;

	return 0;
}