#include <iostream>

using namespace std;

int main339() {

	string a("asd");
	string b("zxc");
	cout << (a < b) << endl;

	const char ca1[] = { 'a','s','d','\0' };
	const char ca2[] = { 'z','x','c','\0' };
	cout << strcmp(ca1, ca2) << endl;

	return 0;
}