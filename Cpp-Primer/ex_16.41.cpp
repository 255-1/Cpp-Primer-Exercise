#include <iostream>

using namespace std;

template<typename T>
auto sum(T lhs, T rhs) ->decltype(lhs + rhs) {
	return lhs + rhs;
}

int main1641()
{
	auto s = sum(1231234645623542546,98579438759896389);
	//https://blog.csdn.net/m0_54206076/article/details/119045705
	//auto s = sum(12345678912345678912345678912345789123456789, 123456789123456789123456789123456789123456789);
	return 0;
}
