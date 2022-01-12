#include <iostream>
#include <string>

using namespace std;

int main510() {

	string input;
	cin >> input;

	int res_count = 0;
	for (auto& c : input) {
		switch (c) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			++res_count;
			break;
		}
	}

	cout << res_count << endl;

	return 0;
}