//#include <iostream>
//#include "Sales_data.h"
//
//int main713() {
//
//	Sales_data total(std::cin);
//	if (!total.isbn().empty()) {
//		std::istream& is = std::cin;
//		while (is) {
//			Sales_data trans(is);
//			if (!is) break;
//			if (total.isbn() == trans.isbn())
//				total.combine(trans);
//			else {
//				print(std::cout, total) << std::endl;
//				total = trans;	
//			}
//		}
//		print(std::cout, total);
//	}
//
//	return 0;
//}