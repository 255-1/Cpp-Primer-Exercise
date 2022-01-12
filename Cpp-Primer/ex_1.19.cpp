#include <iostream>

int main19()
{
	//重写1.11,使其能处理用户输入的第一个数比第二个数小的情况
	int num1, num2;
	std::cin >> num1 >> num2;
	if (num1 > num2) {
		int tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	
	while (num1 <= num2) {
		std::cout << num1++ << std::endl;
	}

	return 0;
}