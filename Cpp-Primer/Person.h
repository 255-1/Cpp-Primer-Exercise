#include <string>
#include <iostream>

class Person;
std::ostream& print(std::ostream& os, const Person&);
std::istream& read(std::istream& is, Person&);

class Person {
	friend std::ostream& print(std::ostream& os, const Person&);
	friend std::istream& read(std::istream& is, Person&);
public:
	Person() = default;
	Person(const std::string& n, const std::string& a) :name(n),address(a) {}
	explicit Person(std::istream& is) { read(is, *this); }
	

	std::string const & getName()const { return name; }
	std::string const & getAddress() const { return address; }
private:
	std::string name;
	std::string address;
};

