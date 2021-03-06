#include "StrBlob.h"
#include <memory>
#include <stdexcept>

StrBlob::StrBlob(): 
	data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) :
	data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string& msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
	check(0, "pop back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}
const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}
std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
const std::string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& 
StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& 
StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

bool StrBlobPtr::operator!=(const StrBlobPtr& p) {
	return p.curr != curr;
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(size_t i, const std::string& msg) const {
	auto ret = wptr.lock();
	if (!ret) throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size()) throw std::out_of_range(msg);
	return ret;
}

ConstStrBlobPtr StrBlob::cbegin() const{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const {
	return ConstStrBlobPtr(*this, data->size());
}

bool ConstStrBlobPtr::operator!=(ConstStrBlobPtr& p) {
	return p.curr != curr;
}


bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data < *rhs.data;
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}

StrBlobPtr& StrBlobPtr_pointer::operator*() const
{
	return *pointer;
}

StrBlobPtr* StrBlobPtr_pointer::operator->() const
{
	return pointer;
}
