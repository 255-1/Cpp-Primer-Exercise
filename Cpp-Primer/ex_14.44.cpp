#include <functional>
#include <iostream>
#include <map>
#include <string>s
using namespace std;

int main1444()
{
	map<string, function<int(int, int)>> binops = {
		{"+",plus<int>()},
		{"-",minus<int>()},
		{"*",multiplies<int>()},
		{"/",divides<int>()},
		{"%",modulus<int>()}
	};

	int num1, num2;
	string op;
	cin >> num1 >> op >> num2;
	cout << binops[op](num1, num2) << endl;
	return 0;
}