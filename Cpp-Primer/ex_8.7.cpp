#include "Sales_data.h"
#include <fstream>
#include <iostream>
#include <string>

int main87(int argc, char** argv) {

	std::ifstream ifs(argv[1]);
	std::ofstream ofs(argv[2], std::ofstream::out|std::ofstream::app);

	Sales_data total;
	if (read(ifs, total)) {
		Sales_data trans;
		while (read(ifs, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(ofs, total) << std::endl;
				total = trans;
			}
		}
		print(ofs, total) << std::endl;
	}
	else {
		std::cerr << "No data" << std::endl;
	}
	ifs.close();
	return 0;
}
