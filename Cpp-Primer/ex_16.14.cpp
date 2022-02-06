#include "Screen.h"
#include <iostream>
using namespace std;

int main1614()
{
	Screen<3, 3> s('a');
	cout << s.get() << endl;
	s.move(1, 1);
	cout << s.get() << endl;

	return 0;
}