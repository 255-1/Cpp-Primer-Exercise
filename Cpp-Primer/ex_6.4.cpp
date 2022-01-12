#include <iostream>

using namespace std;

int fact(int i) {
	return i > 1 ? i * fact(i - 1) : 1;
}

int get_input() {
	const string prompt = "Enter a number within[1,13):\n";
	const string out_of_range = "Out of range\n";
	for (int i; cout << prompt, cin >> i; ) {
		try {
			if (i < 1 || i>12) {
				throw runtime_error(out_of_range);
			}
			return i;
		}
		catch (runtime_error err) {
			cout << err.what() << endl;
			cout << "Try again\n" << endl;
		}
		
	}
}

int main64() {
	
	cout << fact(get_input()) << endl;


	return 0;
}