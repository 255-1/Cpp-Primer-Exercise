#include <string>
#include <iostream>

class Sales_data;
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
std::istream& operator>>(std::istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

class Sales_data {
	//友元函数
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	
public:
	//新增的构造函数
	Sales_data() = default;
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {
		std::cout << "3 params constructures" << std::endl;
	}
	Sales_data(const std::string& s):Sales_data(s,0,0){
		std::cout << "string params constructures" << std::endl;
	}
	Sales_data(std::istream& is):Sales_data("",0,0) { 
		is >> *this;
		std::cout << "istream params constructures" << std::endl;
	}
	

	//成员函数
	Sales_data& operator+=(const Sales_data&);
	//ex_14.13
	Sales_data& operator*=(const int);
	//ex_14.23
	Sales_data& operator=(const std::string& isbn);
	//ex_14.45
	explicit operator std::string() const {
		return bookNo;
	}
	explicit operator double() const {
		return revenue;
	}
	std::string isbn() const {
		return bookNo;
	}
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;	
};
