#include <iostream>

using namespace std;

bool test617(const string& s) {
	for (auto c : s) {
		if (isupper(c))
			return true;
	}
	return false;
}

void testtolower(string& s) {
	for (auto& c : s) {
		c = tolower(c);
	}
}

int main617() {


	return 0;
}