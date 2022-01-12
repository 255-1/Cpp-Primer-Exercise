#include <iostream>

int main17()
{
	int currVal = 0, val = 0;
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs "
					<< cnt << " times " << std::endl;
				currVal = val;
				cnt = 1;
			}
		}

		std::cout << currVal << " occurs "
			<< cnt << " times " << std::endl;
	}
	//都是重复的
	//42 42 42 42 42 ^ Z
	//42 occurs 5 times

	//没有重复的
	//1 2 3 4 5 6 ^ Z
	//1 occurs 1 times
	//2 occurs 1 times
	//3 occurs 1 times
	//4 occurs 1 times
	//5 occurs 1 times
	//6 occurs 1 times
	return 0;
}