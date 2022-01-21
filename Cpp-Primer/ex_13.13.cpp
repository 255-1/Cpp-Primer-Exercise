#include <iostream>
#include <vector>
using namespace std;

struct X
{
	X() { cout << "默认初始化" << endl; }
	X(const X&) { cout << "拷贝构造" << endl; }
	X& operator= (const X& x){
		cout << "拷贝赋值" << endl;
		return *this;
	}
	~X() {
		cout << "析构" << endl;
	}
	void nReference(X x) {
		cout << "非引用调用" << endl;
	}

	void reference(X& x) {
		cout << "引用调用" << endl;
	}
};

int main1313() {
	X x1, x2;
	//拷贝赋值
	//x2 = x1;
	//引用参数传递
	//x1.reference(x2);
	//非引用参数传递
	//x1.nReference(x2);
	//动态分配
	//X* p = new X();
	//delete p;

	vector<X> vec;
	vec.reserve(3);
	vec.emplace_back(x1);
	vec.push_back(x2);

	return 0;
}