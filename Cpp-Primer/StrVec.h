#include <string>
class StrVec {
public:
	StrVec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(const std::initializer_list<std::string>& il);
	StrVec& operator=(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	~StrVec();

	void push_back(const std::string&);
	void push_back(std::string&& s);
	size_t size() const {return first_free - elements;}
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }

	void reserve(size_t new_cap);
	void resize(size_t count);
private:
	std::allocator<std::string> alloc;
	//���Ԫ��ʹ��
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	//�����ڴ沢������ǰ���ݵ��·����ڴ���
	std::pair<std::string*, std::string*> alloc_n_copy (const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string* elements;
	std::string* first_free;
	std::string* cap;
};

