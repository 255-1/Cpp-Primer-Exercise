#include <iostream>

using namespace std;

int main523() {

	int num1, num2;
	cin >> num1 >> num2;
	
	try {
		if (num2 == 0) throw runtime_error("divided by zero");
		cout << static_cast<double>(num1) / num2 << endl;
	}
	catch (runtime_error err) {
		cout << "runtime_error" << endl;
		cout << err.what() << endl;
	}
	catch (exception e) {
		cout << "exception e" << endl;
		cout << e.what() << endl;
	}

	return 0;
}