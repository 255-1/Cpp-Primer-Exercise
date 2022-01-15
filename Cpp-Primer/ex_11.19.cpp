#include <iostream>
#include "Sales_data.h"
#include <set>

bool compareIsbn(const Sales_data& lhs,
	const Sales_data& rhs);

int main1119() {
	using f = bool(*)(const Sales_data&, const Sales_data&);
	std::multiset<Sales_data, f> bookstore(compareIsbn);

	std::multiset<Sales_data, f>::iterator it = bookstore.begin();

	return 0;
}