//#pragma once
//#include <stdio.h>
//#include <string.h>
//#include <utility>
//class String {
//public:
//	//默认构造函数
//	String():
//		data_(new char[1]{ '\0' }) {}
//	//C风格字符串构造函数
//	String(const char* str):
//		data_(new char[strlen(str) + 1]) 
//	{
//		strcpy(data_, str);
//	}
//	//拷贝构造
//	String(const String& rhs)
//		:data_(new char[rhs.size() + 1])
//	{
//		strcpy(data_, rhs.c_str());
//	}
//	//赋值
//	String& operator=(String rhs)
//	{
//		swap(rhs);
//		return *this;
//	}
//	//析构
//	~String() 
//	{
//		delete[] data_;
//	}
//	//swap
//	void swap(String& rhs)
//	{
//		using std::swap;
//		swap(rhs.data_, data_);
//	}
//	//size
//	size_t size() const {
//		return strlen(data_);
//	}
//
//	//c_str
//	const char* c_str()const {
//		return data_;
//	}
//private:
//	char* data_;
//};