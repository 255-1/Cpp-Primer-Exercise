#include <iostream>
#include "Employee.h"

using namespace std;

int main1318() {

	Employee a("a"), b(a);
	Employee c;
	c = b;
	a.print();
	b.print();
	c.print();
	return 0;
}