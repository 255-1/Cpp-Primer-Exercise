#include <iostream>

using namespace std;

int main514() {

	string s1, s2, res_s;
	int res_count=0;
	if (cin >> s1) {
		int cnt = 1;
		while (cin >> s2) {
			if (s2 == s1)
				++cnt;
			else {
				if (cnt > res_count) {
					res_count = cnt;
					res_s = s1;
				}
				cnt = 1;
				s1 = s2;
			}
		}
	}

	cout << res_s << " " << res_count << endl;

	return 0;
}