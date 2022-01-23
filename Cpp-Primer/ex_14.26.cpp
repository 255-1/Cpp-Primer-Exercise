#include "StrVec.h"
#include "String.h"
#include <iostream>
using namespace std;

int main1426()
{
	StrVec vec;
	vec = { "a","b","c" };
	cout << vec[1] <<  endl;

	String s("asdasf");
	cout << s[4] << endl;
	return 0;
}