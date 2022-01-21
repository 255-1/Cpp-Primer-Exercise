#include "HasPtr2.h"
#include <iostream>
using namespace std;

int main1327() {
	HasPtr2 *h1 = new HasPtr2("h1"), h2("h2"), h3(*h1);
	h1->print();
	h2.print();
	h3.print();
	delete h1;
	h3.print();

	h3 = h2;
	h2.print();
	h3.print();
	

	return 0;
}