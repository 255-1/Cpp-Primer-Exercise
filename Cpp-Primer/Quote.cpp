#include "Quote.h"
#include <iostream>

double print_total(std::ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: "
		<< ret << std::endl;
	return ret;
}

double Quote::net_price(std::size_t n) const
{
	std::cout << "Quote net_price" << std::endl;
	return n * price;
}

void Quote::debug() const
{
	std::cout << typeid(*this).name()
		<< " bookNo = " << this->bookNo
		<< " price = " << this->price << std::endl;
}

double Bulk_quote::net_price(std::size_t cnt) const
{
	std::cout << "Bulk_quote   net_price" << std::endl;
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

void Bulk_quote::debug() const
{
	std::cout << typeid(*this).name()
		<< " bookNo = " << this->isbn()
		<< " price = " << this->price 
		<< " quantity = " << this->quantity
		<< " discount = " << this->discount 
		<< std::endl;
}
