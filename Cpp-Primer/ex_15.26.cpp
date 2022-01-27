#include "Quote.h"
#include <iostream>
using namespace std;

int main1526()
{
	cout << "b----------------" << endl;
	Bulk_quote b("a", 1, 1, 1);
	cout << "c----------------" << endl;
	Bulk_quote c = b;
	cout << "d----------------" << endl;
	Bulk_quote d = std::move(c);
	cout << "end----------------" << endl;

	return 0;
}