#include <iostream>
using namespace std;

template <typename T,unsigned N>
inline T* begin166(const T(&arr)[N]) {
	return const_cast<T*>(arr);
}

template <typename T, unsigned N>
inline T* end166(T(&arr)[N]) {
	return arr + N;
}


int main166()
{
	std::string s[] = { "sssss","ss","ss","ssssszzzz" };
	std::cout << *(begin166(s) + 1) << std::endl;
	std::cout << *(end166(s) - 1) << std::endl;

	return 0;
}
