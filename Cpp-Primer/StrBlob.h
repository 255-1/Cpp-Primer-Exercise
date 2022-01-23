#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator<(const StrBlob& lhs, const StrBlob& rhs);
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	//拷贝构造
	StrBlob(const StrBlob& sb)
		:data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
	//拷贝赋值
	StrBlob& operator=(const StrBlob& sb) {
		data = std::make_shared<std::vector<std::string>>(*sb.data);
		return *this;
	}
	size_type size()const { return data->size(); }
	bool empty() const { return data->empty(); }
	std::string& operator[](size_t n) {
		return (*data)[n];
	}
	//添加和删除元素
	void push_back(const std::string& t) {
		data->push_back(t);
	}
	void push_back(std::string&& s) {
		data->push_back(std::move(s));
	}
	void pop_back();
	//元素访问
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	//带入weak_ptr的StrBlobPtr操作
	StrBlobPtr begin();
	StrBlobPtr end();
	//使用ConstStrBlobPtr
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;

};
bool operator<(const StrBlob& lhs, const StrBlob& rhs);
bool operator==(const StrBlob& lhs, const StrBlob& rhs);
bool operator!=(const StrBlob& lhs, const StrBlob& rhs);


//使用weak
class StrBlobPtr {
	friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	bool operator!=(const StrBlobPtr& p);
	std::string operator[](size_t n) {
		return (*wptr.lock())[n];
	}
	StrBlobPtr& operator++() {check(curr, "超出范围");++curr;return *this;}
	StrBlobPtr& operator++(int) {StrBlobPtr ret = *this;++* this;return ret;}
	StrBlobPtr& operator--() {check(curr, "超出范围"); --curr;return *this;}
	StrBlobPtr& operator--(int) {StrBlobPtr ret = *this;--* this;return ret;}
	StrBlobPtr& operator+=(size_t n) {curr += n;check(curr, "超出范围");return *this;}
	StrBlobPtr& operator-=(size_t n) {curr -= n;check(curr, "超出范围");return *this;}
	StrBlobPtr operator+(size_t n) { StrBlobPtr ret = *this; ret += n; return ret; }
	StrBlobPtr operator-(size_t n) { StrBlobPtr ret = *this; ret -= n; return ret; }
	std::string& operator*() const {auto p = check(curr, "超出范围");return (*p)[curr];}
	std::string* operator->() const {
		return &this->operator*();
	}
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::size_t curr;
	std::weak_ptr<std::vector<std::string>> wptr;
};

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
	friend bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
	friend bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
public:
	ConstStrBlobPtr() :curr(0) { }
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) { } // should add const
	bool operator!=(ConstStrBlobPtr& p);
	const std::string& operator*() const {
		auto p = check(curr, "超出范围");
		return (*p)[curr];
	}
	const std::string* operator->() const {
		return &this->operator*();
	}
	const std::string& deref() const { 
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	ConstStrBlobPtr& incr() {
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
private:
	std::shared_ptr<std::vector<std::string>>
		check(size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;

};

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);


class StrBlobPtr_pointer {
public:
	StrBlobPtr_pointer() = default;
	StrBlobPtr_pointer(StrBlobPtr* p):pointer(p){}

	StrBlobPtr& operator*() const;
	StrBlobPtr* operator->() const;
private:
	StrBlobPtr* pointer;
};