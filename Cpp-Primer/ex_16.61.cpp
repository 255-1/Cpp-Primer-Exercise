#include <iostream>
using namespace std;

template <typename T, typename... Args>
auto make_shared1661(Args&&... args)->std::shared_ptr<T>
{
	return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main1661()
{
	auto num = make_shared1661<int>(42);
	auto s = make_shared1661<string>(10,'a');
	cout << *num << endl;
	cout << *s << endl;


	return 0;
}