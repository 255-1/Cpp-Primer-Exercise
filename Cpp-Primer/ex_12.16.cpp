#include <iostream>
#include <memory>

int main1217() {

	std::unique_ptr<int> upi(new int(42));
	//std::unique_ptr<int> upi2(upi);
	std::cout << *upi << std::endl;

	return 0;
}