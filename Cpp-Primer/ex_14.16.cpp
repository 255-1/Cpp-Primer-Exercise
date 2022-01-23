#include "StrVec.h"
#include <iostream>
using namespace std;

int main1416()
{
	StrVec vec1, vec2;
	vec1.push_back("1");
	vec1.push_back("2");
	vec2.push_back("1");

	cout << (vec1 == vec2 ? "equal" : "not equal") << endl;
	return 0;
}