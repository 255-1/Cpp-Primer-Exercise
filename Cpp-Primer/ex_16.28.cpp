#include "SharedPointer.h"
#include <iostream>
#include <vector>
using namespace std;

int main1628()
{
	int *a = new int(5);
	SharedPointer<int> spi1(a);

	//test��ɾ�����Ĺ��캯��
	int* b = new int(7);
	function<void(int*)> newDeleter = [](int* a) {
		std::cout << "��ɾ����" << std::endl;
		delete a;
	};
	SharedPointer<int> spi2(b, newDeleter);

	//test��������
	SharedPointer<int> spi3(spi2); 
	//test ��ֵ
	SharedPointer<int> spi4;
	spi4 = spi3;

	int* c = new int(9);
	//test reset
	spi1.reset(c);

	int* d = new int(11);
	//test reset + ɾ����
	spi1.reset(d, newDeleter);

	//test operator*
	cout << *spi1 << endl;
	//test operator->
	vector<string>* ps = new vector<string>(10, "a");
	cout << ps->front() << endl;
	cout << ps->size() << endl;
	return 0;
}