//#include <iostream>
//using namespace std;
//
//class base {
//public:
//	string name() { return basename; }
//	virtual void print(ostream& os) { os << basename; }
//private:
//	string basename="base";
//};
//
//class derived : public base {
//public:
//	void print(ostream& os) { base::print(os); os << "de" << i; }
//private:
//	int i;
//};
//
//int main1513()
//{
//	base b;
//	b.print(cout);
//	derived d;
//	d.print(cout);
//
//	return 0;
//}