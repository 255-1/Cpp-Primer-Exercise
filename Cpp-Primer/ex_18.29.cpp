#include <iostream>
using namespace std;
class Class {
public:
	Class() {
		cout << "Class" << endl;
	}
	~Class() {
		cout << "~Class" << endl;
	}
};
class Base :public Class {
public:
	Base() {
		cout << "Base" << endl;
	}
	Base(int i):num(i) {
		cout << "Base(int)" << endl;
	}
	Base(const Base& rhs) {
		cout << "Base(cosnt Base&)" << endl;
		num = rhs.num;
	}
	~Base() {
		cout << "~Base" << endl;
	}
	int num = 0;
};

class D1 : virtual public Base {
public:

	D1(){
		cout << "D1" << endl;
	}
	~D1() {
		cout << "~D1" << endl;
	}
};

class D2 : virtual public Base {
public:
	D2() {
		cout << "D2" << endl;
	}
	~D2() {
		cout << "~D2" << endl;
	}
};

class MI : public D1, public D2 {
public:
	MI() {
		cout << "MI" << endl;
	}
	~MI() {
		cout << "~MI" << endl;
	}
};

class Final : public MI, public Class {
public:
	Final() :Base(4) {
		cout << "Final" << endl;
	}
	~Final() {
		cout << "~Final" << endl;
	}
};

int main1829()
{
	Final f;
	cout << f.num << endl;
	
	//Base* pb;
	//Class* pc;
	//MI* pmi;
	//D2* pd2;
	////pb = new Class;
	//pc = new Final;
	//pmi = pb;
	//pd2 = pmi;

	//D2 d2;
	//cout << d2.num << endl;
	return 0;
}