#include <iostream>
using namespace std;

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
	f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2) {
	f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int& v2) {
	cout << v1 << " " << ++v2 << endl;
}
void g(int&& i, int& j) {
	cout << i << " " << j << endl;
}

int main1647()
{
	//int i = 0, j = 0;
	//f(42, i);
	//flip1(f, j, 42);
	//cout << i << " " << j << endl;

	//int i = 0, j = 0;
	//f(42, i);
	//flip2(f, j, 42);
	//cout << i << " " << j << endl;
	//flip2(g, i, 42);

	int i = 0, j = 0;
	f(42, i);
	flip(f, j, 42);
	cout << i << " " << j << endl;
	flip(g, i, 42);
	return 0;
}