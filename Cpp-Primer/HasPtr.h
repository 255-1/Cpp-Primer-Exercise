
#include <string>
#include <iostream>


class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}

	//*(hp.s)拷贝到ps指向位置,而不是拷贝hp的ps指针
	//拷贝构造函数
	HasPtr(const HasPtr& hp) :
		ps(new std::string(*hp.ps)), i(hp.i) {
		//std::cout << "拷贝构造函数" << std::endl;
	}
	//拷贝赋值函数
	HasPtr& operator=(HasPtr hp) {
		std::cout << "拷贝并交换" << std::endl;
		this->swap(hp);
		return *this;
	}

	HasPtr(HasPtr&& p) noexcept:
		ps(p.ps), i(p.i)
	{
		p.ps = nullptr;
		p.i = 0;
		//std::cout << "移动构造函数" << std::endl;
	}
	HasPtr& operator=(HasPtr&& rhs) noexcept {
		if (this != &rhs) {
			ps = rhs.ps;
			i = rhs.i;
			rhs.ps = nullptr;
			rhs.i = 0;
		}
		std::cout << "移动赋值函数" << std::endl;
		return *this;
	}
	//小于比较
	bool operator<(const HasPtr& hp) {
		std::cout << "类内<比较" << std::endl;
		return *(ps) < *(hp.ps);
	}

	void swap(HasPtr& rhs)
	{
		using std::swap;
		swap(ps, rhs.ps);
		swap(i, rhs.i);
		std::cout << "call swap(HasPtr &rhs)" << std::endl;
	}

	//析构函数
	~HasPtr() {
		delete ps;
	}

	//打印
	void print() {
		std::cout << *ps << " " << i << std::endl;
	}


private:
	std::string* ps;
	int i;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs) {
	lhs.swap(rhs);
	std::cout << "swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
	std::cout << "类外<比较" << std::endl;
	return *lhs.ps < *rhs.ps;
}
