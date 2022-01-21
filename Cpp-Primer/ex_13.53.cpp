//#include "HasPtr.h"
//#include <iostream>
//#include <time.h>
//using namespace std;
//
//int main1353()
//{
//	double duration;
//	clock_t start, finish;
//	HasPtr a("A");
//	start = clock();
//	for (int i = 0; i < 1000000; ++i) {
//		HasPtr c = a;
//	}
//	finish = clock();
//	duration = (double)(finish - start) / CLOCKS_PER_SEC;
//	printf("%f seconds\n", duration);
//
//	start = clock();
//	for (int i = 0; i < 1000000; ++i) {
//		HasPtr d = std::move(a);
//	}
//	finish = clock();
//	duration = (double)(finish - start) / CLOCKS_PER_SEC;
//	printf("%f seconds\n", duration);
//
//
//	return 0;
//}