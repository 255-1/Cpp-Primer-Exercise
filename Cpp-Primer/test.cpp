#include <iostream>
#include <vector>
#include "Sales_data.h"
#include "StrVec.h"
#include "Quote.h"
using namespace std;

int next_num() {
	return 1;
}

void reset(int* ip) {
	*ip = 0;
	ip = 0;
}

constexpr int new_sz() { return 42; }
constexpr size_t scale(size_t cnt) { return cnt; }

//constexpr size_t getParam(int n) {
//	int* t = &n;
//	const int* a = const_cast<const int*>(t);
//	int arr[scale(*a)];
//}


class CopyExample {
public:
	CopyExample(int i) :num(i) {}
	CopyExample(const CopyExample& ex) {
		num = ex.num;
		cout << "¿½±´¹¹Ôìº¯Êý" << endl;
	}
	void testCopy(CopyExample ce) {}
private:
	int num;
};

int maintest() {
	Quote* b = new Bulk_quote("a", 1, 1, 0.3);
	cout << b->net_price(2);
	//StrVec vec;
	//string s = "some string or another";
	//vec.push_back(s);
	//vec.push_back("done");

	//int a[5]{0};
	//for (auto it = begin(a); it != end(a); ++it) {
	//	cout << *it << endl;
	//}

	//int* a = new int[5]();
	//unique_ptr<int[]>p(a);
	//for (int i = 0; i < 5; ++i) {
	//	cout << p[i] << endl;
	//}


	//shared_ptr<int> p(new int(100));
	//cout << p.use_count() << endl;
	//weak_ptr<int> wp(p);
	//cout << p.use_count() << endl;
	//if (shared_ptr<int> np = wp.lock()) {
	//	cout << p.use_count() << endl;
	//	cout << np.use_count() << endl;
	//}
	//cout << p.use_count() << endl;
	//string str("asdasdasd");
	//cout << str.find_last_of("scx") << endl;

	/*int arr[getParam(2)];*/


	//int a = 23;
	//int* b = &a;
	//const int* c = const_cast<const int*>(b);
	//cout << *c << endl;

	//const char cc[3]{ 'a','b','\0' };
	//const char* ccp = cc;
	//string s = ccp;
	//cout << s << endl;
	//bool flag = false;

	//switch (flag) {
	//case true:
	//	//string file_name;
	//	//int ival = 0;
	//	int jval;
	//	break;
	//case false:
	//	jval = next_num();
	//	//if (file_name.empty()) {

	//	//}
	//}

	//try {
	//	if (1 != 2) {
	//		throw runtime_error("false");
	//	}
	//}
	//catch (runtime_error err) {
	//	cout << err.what() << endl;
	//}
	//
	//int i = 42;
	//cout << &i << endl;
	//reset(&i);
	//cout << &i << endl;
	//cout << i << endl;

	//auto old_state = cin.rdstate();

	return 0;
}