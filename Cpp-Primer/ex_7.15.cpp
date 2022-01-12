#include <iostream>
#include "Person.h"

int main715() {

	Person p1;
	Person p2("a", "a");
	Person p3(std::cin);

	print(std::cout, p1) << std::endl;
	print(std::cout, p2) << std::endl;
	print(std::cout, p3) << std::endl;
	return 0;
}