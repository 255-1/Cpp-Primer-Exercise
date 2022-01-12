#include <iostream>
#include <string>

using namespace std;

int main34()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 != s2) {
		if (s1 > s2) {
			cout << s1 << endl;
		}
		else {
			cout << s2 << endl;
		}
	}


	//判断s1和s2是否等长
	if (s1.size() != s2.size()) {
		if (s1.size() > s2.size()) {
			cout << s1 << endl;
		}
		else {
			cout << s2 << endl;
		}
	}

	return 0;
}