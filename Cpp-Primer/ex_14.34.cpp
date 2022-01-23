#include <iostream>

class Foo1434 {
public:
	int operator()(const int a, const int b, const int c) {
		return a ? b : c;
	}
};

int main1434()
{
	Foo1434 f;
	int res = f(0, 2, 3);
	std::cout << res  << std::endl;

	return 0;
}