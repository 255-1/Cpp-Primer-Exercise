#include "Account.h"
#include <iostream>

int main757() {

	Account ac1;
	Account ac2;
	std::cout << ac1.rate() << std::endl;
	std::cout << ac1.rate() << std::endl;
	Account::rate(999);
	std::cout << ac1.rate() << std::endl;
	std::cout << ac1.rate() << std::endl;
	ac1.rate(1);
	std::cout << ac1.rate() << std::endl;
	std::cout << ac1.rate() << std::endl;
	return 0;
}
