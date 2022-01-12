#include <iostream>

int main218()
{
	int i = 0, i2 = 1, * p = &i;
	std::cout << "before change p value: " << p << std::endl;
	p = &i2;
	std::cout << "after change p value: " << p << std::endl;
	std::cout << "before change *p value: " << *p << std::endl;
	*p = 2;
	std::cout << "after change *p value: " << *p << std::endl;

	
	return 0;
}