#include <iostream>
#include <string>

using namespace std;

class Foo157
{
public:
	Foo157(string n, size_t c, double co, double d) :
		name(n), cnt(c), cost(co), discount(d) {}

	double price(size_t a) {
		double res = 0;
		if (a <= cnt) {
			res += a * discount * cost;
		}
		else {
			//未超出部分优惠
			res += cnt * discount * cost;
			//超出部分原价
			res += (a - cnt) * cost;
		}
		return res;
	}
private:
	string name;
	size_t cnt;
	double cost;
	double discount;
};

int main157()
{
	Foo157 f("a", 3, 3, 0.5);
	cout << f.price(5);

	return 0;
}