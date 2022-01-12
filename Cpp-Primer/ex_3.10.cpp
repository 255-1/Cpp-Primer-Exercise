#include <iostream>
#include <cctype>

using namespace std;

int main310()
{
	string s("Hello,World!!!");
	for (const auto c : s) {
		if (!ispunct(c)) {
			cout << c;
		}
	}
	
	return 0;
}