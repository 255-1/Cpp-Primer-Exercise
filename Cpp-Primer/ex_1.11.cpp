#include <iostream>

int main11()
{
	std::cout << "Enter two nums: " << std::endl;
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1 < num2) {
		std::cout << num1++ << std::endl;
	}

	return 0;
}