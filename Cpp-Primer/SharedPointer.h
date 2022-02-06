#pragma once
#include <iostream>
#include <functional>
#include "Delete.h"

template <typename T>
class SharedPointer {
public:
	SharedPointer() = default;
	SharedPointer(T* p)
		:ptr(p), ref_count(new std::size_t(1)), deleter(Delete()) {
		std::cout << "不带删除器的构造函数" << std::endl;
		std::cout << typeid(ptr).name() << " " 
			<< *ref_count << " " 
			<< typeid(deleter).name() 
			<< std::endl;
	}
	//初始化带删除器
	SharedPointer(T* p, const std::function<void(T*)>& d)
		:ptr(p), ref_count(new std::size_t(1)), deleter(d) {
		std::cout << "带删除器的构造函数" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
	};
	
	//递增
	SharedPointer(const SharedPointer& o) 
		:ptr(o.ptr),ref_count(o.ref_count),deleter(o.deleter){
		++* ref_count;
		std::cout << "拷贝构造函数" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
	}

	//析构
	~SharedPointer() { decrement_and_destroy(); }
	//赋值递增次数
	SharedPointer& operator=(const SharedPointer& rhs) {
		++* rhs.ref_count;
		decrement_and_destroy();
		ptr = rhs.ptr;
		ref_count = rhs.ref_count;
		deleter = rhs.deleter;
		std::cout << "拷贝函数" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
		return *this;
	}
	//operator*
	T& operator*() const {
		return *ptr;
	}
	//operator->
	T* operator->() const {
		return &*ptr;
	}

	//重置指针不带删除器
	void reset(T* p) {
		if (ptr != p) {
			decrement_and_destroy();
			ptr = p;
			ref_count = new size_t(1);
		}
		std::cout << "重置指针不带删除器" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
	}

	//重置指针带删除器
	void reset(T* p, const std::function<void(T*)>& d) {
		reset(p);
		deleter = d;
		std::cout << "重置指针带删除器" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
	}
private:
	T* ptr;
	std::size_t* ref_count;
	std::function<void(T*)> deleter;

	void decrement_and_destroy()
	{
		if (ptr && 0 == -- * ref_count)
			delete ref_count, deleter(ptr);
		else if (!ptr)
			delete ref_count;
		ref_count = nullptr;
		ptr = nullptr;
	}
};
