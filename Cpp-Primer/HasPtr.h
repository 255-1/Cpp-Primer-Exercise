
#include <string>
#include <iostream>


class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}

	//*(hp.s)������psָ��λ��,�����ǿ���hp��psָ��
	//�������캯��
	HasPtr(const HasPtr& hp) :
		ps(new std::string(*hp.ps)), i(hp.i) {
		//std::cout << "�������캯��" << std::endl;
	}
	//������ֵ����
	HasPtr& operator=(HasPtr hp) {
		std::cout << "����������" << std::endl;
		this->swap(hp);
		return *this;
	}

	HasPtr(HasPtr&& p) noexcept:
		ps(p.ps), i(p.i)
	{
		p.ps = nullptr;
		p.i = 0;
		//std::cout << "�ƶ����캯��" << std::endl;
	}
	HasPtr& operator=(HasPtr&& rhs) noexcept {
		if (this != &rhs) {
			ps = rhs.ps;
			i = rhs.i;
			rhs.ps = nullptr;
			rhs.i = 0;
		}
		std::cout << "�ƶ���ֵ����" << std::endl;
		return *this;
	}
	//С�ڱȽ�
	bool operator<(const HasPtr& hp) {
		std::cout << "����<�Ƚ�" << std::endl;
		return *(ps) < *(hp.ps);
	}

	void swap(HasPtr& rhs)
	{
		using std::swap;
		swap(ps, rhs.ps);
		swap(i, rhs.i);
		std::cout << "call swap(HasPtr &rhs)" << std::endl;
	}

	//��������
	~HasPtr() {
		delete ps;
	}

	//��ӡ
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
	std::cout << "����<�Ƚ�" << std::endl;
	return *lhs.ps < *rhs.ps;
}
