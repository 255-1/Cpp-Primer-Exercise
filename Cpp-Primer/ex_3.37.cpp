#include <iostream>

using namespace std;

int main337() {

	const char ca[] = { 'h','e','l','l','o' };
	const char* cp = ca;
	while (*cp) {
		cout << *cp << endl;
		++cp;
	}


	return 0;
}