#include <iostream>
#include "DebugDelete.h"
using namespace std;

int main1621()
{
	double* p = new double;
	DebugDelete d;
	d(p);

	return 0;
}