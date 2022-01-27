#include "Quote.h"
#include <iostream>
using namespace std;

int main156()
{
	Quote q("a", 10);
	Bulk_quote b("b", 10, 5, 0.5);
	print_total(cout, q, 2);
	print_total(cout, b, 6);


	return 0;
}