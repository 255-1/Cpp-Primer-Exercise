#include <iostream>
#include <string>
using namespace std;

template <typename T>
inline void print(T(&arr))
{
	for (auto elem : arr)
		cout << elem << endl;
}

int main165()
{
	int arr[10]{ 0,1,2,3,4,5,6,7,8,9 };
	string arr2[2]{ "a"," b" };
	print(arr);
	print(arr2);
	return 0;
}