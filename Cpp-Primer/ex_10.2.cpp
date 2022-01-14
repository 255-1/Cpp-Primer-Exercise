#include <list>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main102() {

	list<string> ls{ "a","a","v","b","c","c","c" };
	cout << count(ls.begin(), ls.end(), "a") << endl;

	return 0;
}