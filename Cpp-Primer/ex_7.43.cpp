#include <vector>

class NoDefault {
public:
	NoDefault(int i){
	}
};

class C {
public:
	C() :mem(0) {};
	NoDefault mem;
};

int main743() {
	C c;
	std::vector<C> cv(10);
	

	return 0;
}