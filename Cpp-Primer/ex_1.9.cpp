#include <iostream>

int main9()
{
	int sum = 0, num = 50;
	while (num <= 100) {
		sum += num;
		++num;
	}

	std::cout << sum << std::endl;

	return 0;
}