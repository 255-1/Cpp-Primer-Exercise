#include "Quote.h"
#include <vector>
#include <iostream>
using namespace std;

int main1529() {

	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Quote>("a", 1));
	basket.push_back(make_shared<Quote>("b", 2));
	double total = 0;
	for (const auto& b : basket)
		total += b->net_price(5);
	cout << "total: " << total << endl;
	return 0;
}