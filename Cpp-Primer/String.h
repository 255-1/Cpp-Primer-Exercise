#pragma once

#include <memory>
class String {
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);
	friend bool operator<(const String& lhs, const String& rhs);
public:
	String() : String("") {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;
	~String();

	char operator[](size_t n);
	char* begin() const { return elements; }
	const char* c_str() const { return elements; }
	size_t size()const { return end - elements; }
	size_t length() const { return end - elements - 1; }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
private:
	char* elements;
	char* end;
	std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream&, const String&);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);