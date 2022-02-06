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
		std::cout << "����ɾ�����Ĺ��캯��" << std::endl;
		std::cout << typeid(ptr).name() << " " 
			<< *ref_count << " " 
			<< typeid(deleter).name() 
			<< std::endl;
	}
	//��ʼ����ɾ����
	SharedPointer(T* p, const std::function<void(T*)>& d)
		:ptr(p), ref_count(new std::size_t(1)), deleter(d) {
		std::cout << "��ɾ�����Ĺ��캯��" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
	};
	
	//����
	SharedPointer(const SharedPointer& o) 
		:ptr(o.ptr),ref_count(o.ref_count),deleter(o.deleter){
		++* ref_count;
		std::cout << "�������캯��" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
	}

	//����
	~SharedPointer() { decrement_and_destroy(); }
	//��ֵ��������
	SharedPointer& operator=(const SharedPointer& rhs) {
		++* rhs.ref_count;
		decrement_and_destroy();
		ptr = rhs.ptr;
		ref_count = rhs.ref_count;
		deleter = rhs.deleter;
		std::cout << "��������" << std::endl;
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

	//����ָ�벻��ɾ����
	void reset(T* p) {
		if (ptr != p) {
			decrement_and_destroy();
			ptr = p;
			ref_count = new size_t(1);
		}
		std::cout << "����ָ�벻��ɾ����" << std::endl;
		std::cout << typeid(ptr).name() << " "
			<< *ref_count << " "
			<< typeid(deleter).name()
			<< std::endl;
	}

	//����ָ���ɾ����
	void reset(T* p, const std::function<void(T*)>& d) {
		reset(p);
		deleter = d;
		std::cout << "����ָ���ɾ����" << std::endl;
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
