#include "Person.h"

std::ostream& print(std::ostream& os, const Person& item) {
	os << item.getName() << " " << item.getAddress();
	return os;
}
std::istream& read(std::istream& is, Person& item) {
	is >> item.name >> item.address;
	return is;
}