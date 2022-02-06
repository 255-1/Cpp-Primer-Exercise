//#pragma once
//#include <vector>
//#include <string>
//#include <memory>
//template <typename T> class BlobPtr {
//public:
//	BlobPtr() :curr(0) {}
//	BlobPtr(Blob<T> a, size_t sz = 0) :
//		wptr(a.data), curr(sz) {}
//
//	T& operator*() const {
//		auto p = check(curr, "out of range");
//		return (*p)[curr];
//	}
//	BlobPtr& opeartor++();
//	BlobPtr operator++(int);
//	BlobPtr& opeartor--();
//private:
//	std::shared_ptr<std::vector<T>>
//		check(std::size_t, const std::string& msg) const;
//
//	std::weak_ptr<std::vector<T>> wptr;
//	std::size_t curr;
//	
//};
//
//template<typename T>
//BlobPtr<T> BlobPtr<T>::operator++(int)
//{
//	BlobPtr ret = *this;
//	++* this;
//	return ret;
//}
//
//template<typename T>
//inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t, const std::string& msg) const
//{
//	auto ret = wptr.lock();
//	if (!ret)
//		throw std::runtime_error("unbound BlobPtr");
//	if (i >= ret->size())
//		throw std::out_of_range(msg);
//	return ret;
//}
