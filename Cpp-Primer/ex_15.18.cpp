#include <iostream>
using namespace std;
class Base {
public:
	void pub_mem() { cout << "Base->pub_mem()" << endl; }
	void memfcn(Base& b) { b = *this; }
protected:
	int prot_mem;
private:
	char priv_mem;
};

class Sneaky : public Base
{
	friend void clobber(Sneaky&);
	//friend void clobber(Base&);
	int j;
	//void memfcn(Base& b) { b = *this; }
};
void clobber(Sneaky& s) { s.j = s.prot_mem = 0; }
//void clobber(Base& b) { b.prot_mem == 0; }

struct Pub_Derv : public Base
{
	void memfcn(Base& b) { b = *this; }
	void e() { pub_mem(); }
	int f() { return prot_mem; };
	//char g() { return priv_mem; }
};

struct Priv_Derv : private Base
{
	//void memfcn(Base& b) { b = *this; }
	int e1() { pub_mem(); }
	int f1() const { return prot_mem; }
	int p;
};
struct Derived_from_Public : public Pub_Derv
{
	void memfcn(Base& b) { b = *this; }
	int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv
{
	//void memfcn(Base& b) { b = *this; }
	int use_base() { return p; }
};
int main1518()
{
	//Pub_Derv d1;
	//Priv_Derv d2;
	//Derived_from_Public dd1;
	//Derived_from_Private dd2;
	//d1.pub_mem();
	//Base* p = &d1;
	//p = &dd1;



	return 0;
}