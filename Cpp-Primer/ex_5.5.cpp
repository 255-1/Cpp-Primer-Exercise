#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main55() {

	const vector<string> scores{ "F","D","C","B","A","A++" };
	string res;
	int grade = 60;
	if (grade < 60)
		res = scores[0];
	else
		res = scores[(grade - 50) / 10];

	cout << res << endl;

	return 0;
}