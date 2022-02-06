#include "StrVec.h"
#include <algorithm>
#include <iostream>
StrVec::StrVec(const StrVec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const std::initializer_list<std::string>& il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	cap = first_free = data.second;
	return *this;
}

StrVec::StrVec(StrVec&& s) noexcept:
	elements(s.elements), first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
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

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::push_back(const std::string& s)
{
	std::cout << "拷贝 push back" << std::endl;
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string&& s)
{
	std::cout << "移动 push back" << std::endl;
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

void StrVec::reserve(size_t new_cap)
{
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

void StrVec::resize(size_t count)
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

template<class ...Args>
inline 
void StrVec::emplace_back(Args && ... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements) {
		/*for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);*/

		//ex13.43
		for_each(elements, first_free,
			[this](std::string& rhs) {alloc.destroy(&rhs); });
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	//move
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

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
	return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(),
		rhs.begin(), rhs.end());
}
