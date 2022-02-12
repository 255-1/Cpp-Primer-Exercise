#include <iostream>
namespace primerLib {
	void compute();
	void compute(const void*);
}

using primerLib::compute;
void compute(int) {};
void compute(double, double = 3.14);
void compute(char*, char*);

void ff() {
	compute(0);
}

int main1820() {
	ff();
	return 0;
}