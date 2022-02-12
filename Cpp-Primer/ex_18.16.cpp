#include <iostream>

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;


int main1816() {
	using Exercise::ivar;
	using Exercise::dvar;
	using Exercise::limit;
	std::cout << "ivar = " << ivar << std::endl;

	std::cout << "dvar = " << dvar << std::endl;
	//double dvar = 3.1416;
	dvar = 3.1416;
	std::cout << "dvar = " << dvar << std::endl;

	int iobj = limit + 1;
	std::cout << "iobj = " << iobj << std::endl;

	++ivar;
	std::cout << "ivar = " << ivar << std::endl;

	++::ivar;
	std::cout << "::ivar = " << ::ivar << std::endl;
	return 0;
}