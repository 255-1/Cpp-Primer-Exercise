#include <iostream>
#include <initializer_list>

void func627(std::initializer_list<int> li) {
	int sum = 0;
	for (int e : li) {
		sum += e;
	}
	std::cout << sum << std::endl;
}

int main627() {

	func627({1,3,5,7,8,6,4,3,2});

	return 0;
}