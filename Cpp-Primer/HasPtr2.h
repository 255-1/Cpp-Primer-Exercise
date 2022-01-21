#include <string>
#include <iostream>

class HasPtr2 {
public:
	HasPtr2(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	//拷贝构造函数
	HasPtr2(const HasPtr2& p):
	 ps(p.ps), i(p.i), use(p.use){
		++* use;
	}
	~HasPtr2() {
		if (-- * use == 0) {
			delete ps;
			delete use;
		}
	}
	//拷贝赋值函数
	HasPtr2& operator=(const HasPtr2& rhs) {
		++* rhs.use;
		if (-- * use == 0) {
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}

	void print() {
		std::cout << *ps << " " << *use << std::endl;
	}
private:
	std::string* ps;
	int i;
	std::size_t* use;
};