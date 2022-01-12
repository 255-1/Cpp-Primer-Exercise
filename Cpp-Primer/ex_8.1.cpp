#include <iostream>

std::istream& func81(std::istream& is) {
	std::string s;
	while (!is.eof()) {
		is >> s;
		std::cout << s << std::endl;
	}
	std::cout << is.rdstate() << std::endl;
	//¸´Î»eof
	is.clear();
	return is;
}

int main81() {

	std::istream &is = func81(std::cin);
	std::cout << is.rdstate() << std::endl;
	return 0;
}