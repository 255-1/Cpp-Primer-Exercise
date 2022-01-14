#include <stack>
#include <deque>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main952() {
	string str("(1+2)*(3+4)");
	stack<char> ss;
	for (size_t pos = 0; pos != str.size(); ++pos) {
		if (str[pos] != ')') {
			ss.push(str[pos]);
		}
		else {
			string expression("");
			while (ss.top() != '(') {
				cout << ss.top() << " ";
				ss.pop();
			}
			cout << endl;
		}
	}

	return 0;
}