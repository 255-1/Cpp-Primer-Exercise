#include <iostream>

int main5()
{
	std::cout << "Enter two nums: ";
	std::cout << std::endl;
	int num1, num2;
	std::cin >> num1;
	std::cin >> num2;
	std::cout << "The result of ";
	std::cout << num1;
	std::cout << " times ";
	std::cout << num2 << " = ";
	std::cout << num1 * num2;
	std::cout << std::endl;

	return 0;
}