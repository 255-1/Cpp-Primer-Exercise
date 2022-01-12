#include <iostream>
#include <vector>

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


int maintest() {

	string str("asdasdasd");
	cout << str.find_last_of("scx") << endl;

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