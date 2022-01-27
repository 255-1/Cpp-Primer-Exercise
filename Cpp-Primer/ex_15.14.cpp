#include <iostream>
using namespace std;

class base {
public:
	string name() { return basename; }
	virtual void print(ostream& os) { os << basename; }
private:
	string basename = "base";
};

class derived : public base {
public:
	void print(ostream& os) override { os << "de"; }
private:
	int i;
};

int main1514()
{
    base bobj;
    base* bp1 = &bobj;
    base& br1 = bobj;
    derived dobj;
    base* bp2 = &dobj;
    base& br2 = dobj;

    // a.  this is an object, so compile time.
    //bobj.print(std::cout);

    // b.  this is an object, so compile time.
    //dobj.print(std::cout);

    // c.  function name is not virtual , so no dynamic
    //     binding happens.so compile time
    //std::cout << bp1->name();

    // d.  function name is not virtual , so no dynamic
    //     binding happens.so compile time
    //std::cout << bp2->name();

    // e.  run time
    //br1.print(std::cout);

    // f.  run time
    br2.print(std::cout);


    return 0;
}