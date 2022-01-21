#include "String.h"
#include <algorithm>
#include <iostream>
String::String(const char* s) 
{
	char* sl = const_cast<char*>(s);
	while (*sl) ++sl;
	range_initializer(s, ++sl);
}

String::String(const String& rhs)
{
	range_initializer(rhs.elements, rhs.end);
	std::cout << "拷贝构造函数" << std::endl;
}

String& String::operator=(const String& rhs)
{
	auto newdata = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newdata.first;
	end = newdata.second;
	std::cout << "拷贝赋值函数" << std::endl;
	return *this;
}

String::String(String&& s) noexcept:
	elements(s.elements),end(s.end)
{
	std::cout << " 移动构造函数" << std::endl;
	s.elements = s.end = nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
	}
	return *this;
}

String::~String()
{
	free();
}
std::pair<char*, char*>
String::alloc_n_copy(const char* b, const char* e)
{
	auto str = alloc.allocate(e - b);
	return { str, std::uninitialized_copy(b, e, str) };
}
void String::range_initializer(const char* b, const char* e)
{
	auto newdata = alloc_n_copy(b, e);
	elements = newdata.first;
	end = newdata.second;
}
void String::free()
{
	if (elements) {
		std::for_each(elements, end, [this](char& c) {alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}
}
