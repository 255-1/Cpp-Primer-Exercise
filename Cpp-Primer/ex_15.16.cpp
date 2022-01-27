#include "Quote.h"
#include <iostream>

class Foo1516 : public Disc_quote
{
public:
	Foo1516(const std::string& book, double sales_price,
		std::size_t n, double d) :
		Disc_quote(book, sales_price, n, d) {}
	double net_price(size_t a) const override{
		double res = 0;
		if (a <= quantity) {
			res += a * discount * price;
		}
		else {
			//未超出部分优惠
			res += quantity * discount * price;
			//超出部分原价
			res += (a - quantity) * price;
		}
		return res;
	}
};

int main1516()
{

	Foo1516 f("a", 10, 5, .5);
	std::cout << f.net_price(5);
	return 0;
}