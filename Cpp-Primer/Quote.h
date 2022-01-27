#pragma once
#include <iostream>
#include <string>
class Quote
{
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) :
		bookNo(book), price(sales_price) {
		std::cout << "Quote������" << std::endl;
	}
	std::string isbn() const { return bookNo; }
	//��ֵ����
	Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {
		std::cout << "Quote��ֵ����" << std::endl;
	}
	//�ƶ�����
	Quote(Quote&& q)noexcept :
		bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
		q.bookNo = "";
		q.price = 0.0;
		std::cout << "Quote�ƶ�����" << std::endl;
	}
	// ��ֵ
	Quote& operator=(const Quote& rhs) {
		if (this != &rhs) {
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		std::cout << "Quote��ֵ" << std::endl;
		return *this;
	}
	Quote& operator =(Quote&& rhs)  noexcept
	{
		if (this != &rhs)
		{
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		std::cout << "Quote�ƶ�" << std::endl;

		return *this;
	}
	// �ƶ�
	//�麯��
	virtual double net_price(std::size_t n) const;
	virtual void debug() const;
	virtual ~Quote() {
		std::cout << "Quote����" << std::endl;
	};

	//�鿽��
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() const && { return new Quote(std::move(*this)); }
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(std::ostream& os,const Quote& item, size_t n);

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book,
		double price,
		std::size_t qty,
		double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}
	//��������
	Disc_quote(const Disc_quote& d):
		Quote(d),quantity(d.quantity),discount(d.discount) {
		std::cout << "Disc_quote��ֵ����" << std::endl;
	}
	//�ƶ�����
	Disc_quote(Disc_quote&& d) noexcept :
		Quote(d), quantity(std::move(d.quantity)), discount(std::move(d.discount)) {
		std::cout << "Disc_quote�ƶ�����" << std::endl;
	}
	//��ֵ
	Disc_quote& operator=(const Disc_quote& rhs) {
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		std::cout << "Disc_quote��ֵ" << std::endl;
		return *this;
	}





	//�ƶ�
	Disc_quote& operator=(Disc_quote&& rhs)noexcept {
		Quote::operator=(std::move(rhs));
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
		rhs.quantity = 0;
		rhs.discount = 0.0;
		std::cout << "Disc_quote�ƶ�" << std::endl;
		return *this;
	}
	~Disc_quote() override {
		std::cout << "Disc_quote����" << std::endl;
	}
	double net_price(std::size_t) const override = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
	using Disc_quote::Disc_quote;
	/*Bulk_quote() = default;
	Bulk_quote(const std::string& book, double sales_price,
		std::size_t n, double d) :
		Disc_quote(book, sales_price, n, d) {}*/
	//��������
	Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq)
	{
		std::cout << "Bulk_quote��ֵ����" << std::endl;
	}

	// move constructor
	Bulk_quote(Bulk_quote&& bq) noexcept : Disc_quote(std::move(bq))
	{
		std::cout << "Bulk_quote�ƶ�����" << std::endl;
	}

	// copy =()
	Bulk_quote& operator =(const Bulk_quote& rhs)
	{
		Disc_quote::operator =(rhs);
		std::cout << "Bulk_quote��ֵ" << std::endl;

		return *this;
	}


	// move =()
	Bulk_quote& operator =(Bulk_quote&& rhs) noexcept
	{
		Disc_quote::operator =(std::move(rhs));
		std::cout << "Bulk_quote�ƶ�" << std::endl;

		return *this;
	}

	~Bulk_quote() override
	{
		std::cout << "Bulk_quote����" << std::endl;
	}
	double net_price(std::size_t n) const override;
	void debug() const override;
	//�追��
	Bulk_quote* clone() const& { return new Bulk_quote(*this); }
	Bulk_quote* clone() const&& { return new Bulk_quote(std::move(*this)); }

};