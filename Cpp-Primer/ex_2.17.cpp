#include <iostream>

int main217()
{
	int i, & ri = i, i2=0, i3 = 1;
	i = 5; ri = 10;
	ri = i2;
	ri = i3;
	std::cout << i << " " << i2 << " " << i3<< " " << ri << std::endl;

	return 0;
}