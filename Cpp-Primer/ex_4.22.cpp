#include <iostream>
#include <string>

using namespace std;

int main422() {

	//condition
	int grade;
	cin >> grade;
	cout << (grade > 90 ? "high pass" : (grade >= 60 && grade<=75)? "low pass": (grade<60)?"fail":"pass");

	return 0;
}