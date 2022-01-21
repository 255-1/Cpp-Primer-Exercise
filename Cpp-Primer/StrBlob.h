#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	//��������
	StrBlob(const StrBlob& sb)
		:data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
	//������ֵ
	StrBlob& operator=(const StrBlob& sb) {
		data = std::make_shared<std::vector<std::string>>(*sb.data);
		return *this;
	}
	size_type size()const { return data->size(); }
	bool empty() const { return data->empty(); }
	//��Ӻ�ɾ��Ԫ��
	void push_back(const std::string& t) {
		data->push_back(t);
	}
	void push_back(std::string&& s) {
		data->push_back(std::move(s));
	}
	void pop_back();
	//Ԫ�ط���
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	//����weak_ptr��StrBlobPtr����
	StrBlobPtr begin();
	StrBlobPtr end();
	//ʹ��ConstStrBlobPtr
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;

};

//ʹ��weak
class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	bool operator!=(const StrBlobPtr& p);
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::size_t curr;
	std::weak_ptr<std::vector<std::string>> wptr;
};

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() :curr(0) { }
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) { } // should add const
	bool operator!=(ConstStrBlobPtr& p);
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