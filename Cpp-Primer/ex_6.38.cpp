#include <string>
#include <iostream>
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
decltype(odd)& arrPtr(int i) {
	return (i % 2) ? odd : even;
}

int calc(int a, int b);
int calc(const int a, const int b);

int main638() {

	//for (int e : arrPtr(1)) {
	//	std::cout << e << " ";
	//}
	//std::cout << std::endl;


	return 0;
}