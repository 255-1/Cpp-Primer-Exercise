#include "Sales_data.h"

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator*=(const int n)
{
	units_sold *= n;
	revenue *= n;
	return *this;
}

Sales_data& Sales_data::operator=(const std::string& isbn)
{
	*this = Sales_data(isbn);
	return *this;
}

inline double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

std::istream& operator>>(std::istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}


//移入类内部
//Sales_data::Sales_data(std::istream& is) {
//	read(is, *this);
//}