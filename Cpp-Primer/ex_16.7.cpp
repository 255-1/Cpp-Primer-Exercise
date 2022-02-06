#include <iostream>


template<typename T, size_t N>
constexpr size_t func167(T(&arr)[N]) {
	return N;
}

int main167()
{
	int arr[10];
	std::cout << func167(arr) << std::endl;

	return 0;
}