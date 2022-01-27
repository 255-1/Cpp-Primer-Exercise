#include "Quote.h"
#include <vector>
#include <iostream>
using namespace std;

int main1528() {

	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Bulk_quote>("a", 1, 1, .5));
	basket.push_back(make_shared<Bulk_quote>("b", 2, 2, .5));
	double total = 0;
	for (const auto& b : basket)
		total += b->net_price(5);
	cout << "total: " << total << endl;
	return 0;
}