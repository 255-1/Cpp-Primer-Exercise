#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Foo1436 {
public:
	string operator()(istream& is = cin) {
		if (!is) return string();
		string s;
		getline(is, s);
		return s;
	}
};

int main1436()
{
	Foo1436 f;
	vector<string> vs;
	string ret;
	while ((ret=f())!=string()) {
		vs.push_back(ret);
	}
	copy(vs.begin(), vs.end(), ostream_iterator<string>(cout," "));
	
	return 0;
}