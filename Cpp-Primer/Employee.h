#include <string>

class Employee {
public:
	Employee():name(""), no(global++) {}
	Employee(std::string n):name(n),no(global++) {}
	Employee(const Employee& e):name(e.name),no(global++) {
	}
	Employee& operator=(const Employee& e) {
		name = e.name;
		no = global++;
		return *this;
	}
	void print() {
		std::cout << name << " " << no << std::endl;
	}
private:
	std::string name;
	int no;
	static int global;
};
int Employee::global = 1;