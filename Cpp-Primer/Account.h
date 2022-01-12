#include <string>
#include <iostream>

class Account {
public:
	void calculate(){
		amount += amount * interestRate;
	}
	static double rate() { return interestRate; }
	static void rate(double newRate) {
		interestRate = newRate;
	}

private:
	std::string owner;
	double amount=1;
	static double interestRate;
	static constexpr double todayRate = 42.42;
	static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

