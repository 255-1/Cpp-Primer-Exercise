#include <memory>
#include <iostream>
#include "StrVec.h"
using namespace std;
//
//void* operator new(size_t t) {
//	cout << "operator new " << endl;
//	if (void* mem = malloc(t))
//		return mem;
//	else
//		throw bad_alloc();
//}
//
//void operator delete(void* mem) noexcept {
//	cout << "operator delete " << endl;
//	free(mem);
//}

int main191() {
	//int* a = new int(1);
	//delete(a);
	//有多个operator 输出,因为之前的习题有全局变量
	//ex_19.2
	StrVec s({ "a","b","c" });

	return 0;
}