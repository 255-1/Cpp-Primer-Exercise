#pragma once
#include <stdexcept>
#include <algorithm>
#include <iostream>
template <typename T> class Vec;
template <typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs);
template <typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs);

//懒得实现move操作
template <typename T>
class Vec {
	friend bool operator==<T>(const Vec<T>& lhs, const Vec<T>& rhs);
	friend bool operator!=<T>(const Vec<T>& lhs, const Vec<T>& rhs);
public:
	Vec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const std::initializer_list<T>& il);
	Vec(const Vec&);
	Vec(Vec&&) noexcept;
	~Vec();

	Vec& operator=(const Vec&);
	Vec& operator=(std::initializer_list<T> il);
	Vec& operator=(Vec&&) noexcept;
	T& operator[](size_t n) {
		auto loc = elements + n;
		if (loc >= first_free)
			throw std::out_of_range("下标超出范围");
		return *loc;
	};

	void push_back(const T&);
	void push_back(T&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T* begin() const { return elements; }
	T* end() const { return first_free; }
	void reserve(size_t new_cap);
	void resize(size_t count);
	void reallocate();
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
private:
	std::allocator<T> alloc;
	//添加元素使用
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	//分配内存并拷贝当前内容到新分配内存中
	/*std::pair<T*, T*> alloc_n_copy(const T*, const T*);*/
	void free();
	/*void reallocate();*/

	T* elements;
	T* first_free;
	T* cap;
};
template<typename T>
inline Vec<T>::Vec(const Vec<T>& v)
{
	auto newdata = alloc_n_copy(v.begin(), v.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template<typename T>
inline Vec<T>::Vec(const std::initializer_list<T>& il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template<typename T>
inline Vec<T>::Vec(Vec&& v) noexcept
	:elements(v.elements),first_free(v.first_free),cap(v.cap)
{
	v.elements = v.first_free = v.cap = nullptr;
}
template<typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b,e,data) };
}
template<typename T>
inline Vec<T>::~Vec()
{
	free();
}

template<typename T>
inline Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	cap = first_free = data.second;
	return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T>il) {
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename T>
inline Vec<T>& Vec<T>::operator=(Vec&& rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template<typename T>
inline void Vec<T>::push_back(const T& t)
{
	std::cout << "拷贝 push back" << std::endl;
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

template<typename T>
inline void Vec<T>::push_back(T&& t)
{
	std::cout << "移动 push back" << std::endl;
	chk_n_alloc();
	alloc.construct(first_free++, std::move(t));
}

template<typename T>
inline void Vec<T>::reserve(size_t new_cap) {
	//修改reallocate完成reserve功能
	if (new_cap <= capacity()) return;
	auto newdata = alloc.allocate(new_cap);
	//move
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}

template<typename T>
inline void Vec<T>::resize(size_t count)
{
	if (count > size()) {
		if (count > capacity()) reserve(count * 2);
		//多余的用空字符串初始化
		for (size_t i = size(); i != count; ++i)
			alloc.construct(first_free++, "");
	}
	else if (count < size())
	{
		while (first_free != elements + count)
		{
			alloc.destroy(--first_free);
		}
	}
}

template<typename T>
void Vec<T>::free() {
	//std::cout << "free()" << std::endl;
	if (elements) {
		std::for_each(elements, first_free,
			[this](T& rhs) {alloc.destroy(&rhs); });
		alloc.deallocate(elements, cap - elements);
	}
}

template<typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

//-----------------------------------friend--------------------------------
template <typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs) {
	return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs) {
	return !(lhs == rhs);
}
