//#include "Sales_data.h"
//#include <fstream>
//#include <iostream>
//#include <string>
//
//int main86(int argc, char**argv) {
//	
//	std::ifstream ifs(argv[1]);
//	Sales_data total;
//	if (read(ifs, total)) {
//		Sales_data trans;
//		while (read(ifs, total)) {
//			if (total.isbn() == trans.isbn()) {
//				total.combine(trans);
//			}
//			else {
//				print(std::cout, total) << std::endl;
//				total = trans;
//			}
//		}
//		print(std::cout, total) << std::endl;
//	}
//	else {
//		std::cerr << "No data" << std::endl;
//	}
//	ifs.close();
//	return 0;
//}
