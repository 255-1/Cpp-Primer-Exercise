#pragma once
#include <map>
#include <string>
class Shape
{
public:
	using Coordinate = std::pair<double, double>;
	Shape() = default;
	Shape(const std::string& s) : name(s) {}

	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual ~Shape() {}
private:
	std::string name;
};


class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(const std::string& s,
		const Coordinate& a,
		const Coordinate& b,
		const Coordinate& c,
		const Coordinate& d) :
		Shape(s), x1(a), y1(b), x2(c), y2(d) {}

	double area() const override;
	double perimeter() const override;
	~Rectangle() = default;
protected:
	Coordinate x1;
	Coordinate y1;
	Coordinate x2;
	Coordinate y2;
};

