#include <iostream>

int main13()
{
	//ÖØÐ´1.9
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;
	std::cout << sum << std::endl;

	//ÖØÐ´1.10
	for (int i = 10; i >= 0; --i) {
		std::cout << i << std::endl;
	}

	//ÖØÐ´1.11
	std::cout << "Enter two nums: " << std::endl;
	int num1, num2;
	for (std::cin >> num1 >> num2; num1 <= num2; ++num1) {
		std::cout << num1 << std::endl;
	}

	return 0;
}