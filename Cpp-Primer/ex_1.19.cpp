#include <iostream>

int main19()
{
	//��д1.11,ʹ���ܴ����û�����ĵ�һ�����ȵڶ�����С�����
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