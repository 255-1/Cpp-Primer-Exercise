#include <iostream>
#include <vector>
using namespace std;

struct X
{
	X() { cout << "Ĭ�ϳ�ʼ��" << endl; }
	X(const X&) { cout << "��������" << endl; }
	X& operator= (const X& x){
		cout << "������ֵ" << endl;
		return *this;
	}
	~X() {
		cout << "����" << endl;
	}
	void nReference(X x) {
		cout << "�����õ���" << endl;
	}

	void reference(X& x) {
		cout << "���õ���" << endl;
	}
};

int main1313() {
	X x1, x2;
	//������ֵ
	//x2 = x1;
	//���ò�������
	//x1.reference(x2);
	//�����ò�������
	//x1.nReference(x2);
	//��̬����
	//X* p = new X();
	//delete p;

	vector<X> vec;
	vec.reserve(3);
	vec.emplace_back(x1);
	vec.push_back(x2);

	return 0;
}