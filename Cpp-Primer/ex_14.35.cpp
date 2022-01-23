#include <iostream>
#include <string>
using namespace std;

class Foo1435 {
public:
	string operator()(istream& is=cin) {
		if (!is) return string();
		string s;
		is >> s;
		return s;
	}
};

int main1435()
{
	Foo1435 f;
	cout << f() << endl;

	return 0;
}