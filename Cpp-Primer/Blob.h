#pragma once
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include "SharedPointer.h"
template<typename> class BlobPtr;
template<typename> class Blob;
template <typename T>
	bool operator==(const Blob<T>& lhs, const Blob<T>& rhs);
template <typename T>
	bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs);
template <typename T>
	bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator!=<T>(const Blob<T>&, const Blob<T>&); 
public:
	using value_type = T;
	using size_type = typename std::vector<T>::size_type;

	Blob();
	Blob(std::initializer_list<T> il);
	//ex_16.24 
	template <typename It> Blob(It b, It e);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//Ìí¼Ó
	void push_back(const T& t) { data->push_back(t); }
	void push_back(const T&& t) { data->push_back(std::move(t)); }
	void pop_back();
	//·ÃÎÊ
	T& front();
	T& back();
	//ex_16.12
	const T& front() const;
	const T& back() const;
	BlobPtr<T> begin();
	BlobPtr<T> end();

	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	//ex_16.29
	//SharedPointer<std::vector<T>> data;
	void check(size_type i, const std::string& msg) const;
};


template <typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}

	T& operator*() const {
		auto p = check(curr, "out of range");
		return (*p)[curr];
	}
	BlobPtr& operator++() { check(curr, "³¬³ö·¶Î§"); ++curr; return *this; };
	BlobPtr operator++(int);
	BlobPtr& operator--() { check(curr, "³¬³ö·¶Î§"); --curr; return *this; };
private:
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string& msg) const;

	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;

};

//--------------------------definition----------------------------
template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
	return *lhs.data == *rhs.data;
}
template <typename T>
bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return !(lhs == rhs);
}
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr == rhs.curr;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++* this;
	return ret;
}

template<typename T>
inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
template<typename T>
inline Blob<T>::Blob()
 :data(std::make_shared<std::vector<T>>()){}

////ex_16.29Ç³³¢
//template<typename T>
//inline Blob<T>::Blob()
//	: data(SharedPointer<std::vector<T>>(new std::vector<T>())) {}

template<typename T>
inline Blob<T>::Blob(std::initializer_list<T> il)
	:data(std::make_shared<std::vector<T>>(il)){}

template<typename T>
template<typename It>
inline Blob<T>::Blob(It b, It e)
	:data(std::make_shared<std::vector<T>>(b, e)){}

template<typename T>
inline void Blob<T>::pop_back()
{
	check(0, "pop on empty Blob");
	data->pop_back();
}

template<typename T>
inline T& Blob<T>::front()
{
	check(0, "back on empty Blob");
	return data->front();
}

template<typename T>
inline T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline const T& Blob<T>::front() const
{
	check(0, "back on empty Blob");
	return data->front();
}

template<typename T>
inline const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline BlobPtr<T> Blob<T>::begin()
{
	return BlobPtr<T>(*this);
}

template<typename T>
inline BlobPtr<T> Blob<T>::end()
{
	return BlobPtr<T>(*this, data->size());
}

template<typename T>
inline T& Blob<T>::operator[](size_type i)
{
	check(i, "out of range");
	return (*data)[i];
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}
