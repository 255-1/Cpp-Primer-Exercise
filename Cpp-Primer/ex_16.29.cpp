#include "Blob.h"
using namespace std;

int main1629()
{
	int ia[] = { 1,2,3,4,5 };
	Blob<int> test;
	test.push_back(4);
	cout << test.back() << endl;	
	test.push_back(3);
	cout << test.back() << endl;
	return 0;

}