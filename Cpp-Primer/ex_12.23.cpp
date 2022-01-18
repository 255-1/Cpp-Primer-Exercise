#include <iostream>
#include <string>
using namespace std;

int main1223() 
{
	char c1[4] = "asd";
	char c2[4] = "fgh";
	char* c = new char[7]();
	for (char* q = c; q != c + 7; ++q) {
		if (q < c + 3) {
			*q = c1[q - c];
		}
		else {
			*q = c2[q - c - 3];
		}
	}
	cout << string(c) << endl;
	delete[] c;
	string s1("asd");
	string s2("fgh");
	cout << s1 + s2 << endl;

	return 0;
}