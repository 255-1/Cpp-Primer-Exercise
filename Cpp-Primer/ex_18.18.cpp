#include <iostream>
#include <string>
template<typename T>
void swap(T v1, T v2) {
	using std::swap;
	swap(v1.mem1, v2.mem1);
	v1.print();
	v2.print();
}

class Ex1818 {
public:
	Ex1818(const std::string& s) :mem1(s) {}
	void print() {
		std::cout << mem1 << std::endl;
	}
	std::string mem1;
};
class Ex1818_2 {
public:
	Ex1818_2(int s) :mem1(s) {}
	void print() {
		std::cout << mem1 << std::endl;
	}
	int mem1;
};
int main1818() {

	Ex1818_2 s1(1);
	Ex1818_2 s2(2);

	return 0;
}