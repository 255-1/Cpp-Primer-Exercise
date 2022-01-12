#include <iostream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

int main241() {

	//重写1.20
	//Sales_data s1;
	//std::cin >> s1.bookNo >> s1.units_sold >> s1.revenue;
	//std::cout << s1.bookNo << s1.units_sold << s1.revenue;

	//重写1.21
	//Sales_data s1, s2;
	//double price = 0;
	//std::cin >> s1.bookNo >> s1.units_sold >> s1.revenue;
	//std::cin >> s2.bookNo >> s2.units_sold >> s2.revenue;
	//std::cout << s1.units_sold * s1.revenue + s2.units_sold * s2.revenue;

	//重写1.22
	//double price = 0;
	//Sales_data s1, s2;
	//if (std::cin >> s1.bookNo >> s1.units_sold >> s1.revenue) {
	//	price += s1.units_sold * s1.revenue;
	//	while (std::cin >> s2.bookNo >> s2.units_sold >> s2.revenue) {
	//		price += s2.units_sold * s2.revenue;
	//	}
	//}
	//std::cout << price << std::endl;

	//重写1.23, 1.24
	//Sales_data s1,s2;
	//if (std::cin >> s1.bookNo >> s1.units_sold >> s1.revenue) {
	//	int cnt = 1;
	//	while (std::cin >> s2.bookNo >> s2.units_sold >> s2.revenue) {
	//		if (s1.bookNo == s2.bookNo) {
	//			++cnt;
	//		}
	//		else {
	//			std::cout << s1.bookNo << " " << cnt << std::endl;
	//			cnt = 1;
	//			s1 = s2;
	//		}
	//	}
	//	std::cout << s1.bookNo << " " << cnt << std::endl;
	//}
	



	return 0;
}