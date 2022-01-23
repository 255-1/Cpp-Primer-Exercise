#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void elimDups(vector<string>& vs);
class Foo1440_1 {
public:
	bool operator()(const string& a, const string& b)
	{
		return a.size() < b.size();
	}
};

class Foo1440_2 {
public:
	Foo1440_2(const int s) : sz(s) {}
	bool operator()(const string& a)
	{
		return a.size() >= sz;
	}
private:
	int sz;
};

class Foo1440_3 {
public:
	void operator()(const string& s)
	{
		cout << s << " ";
	}
};

void biggies1440(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), Foo1440_1());
	auto wc = find_if(words.begin(), words.end(), Foo1440_2(sz));
	auto count = words.end() - wc;
	cout << count << endl;
	for_each(wc, words.end(), Foo1440_3());
}

int main1440()
{
	vector<string> vs{ "the","quick","red","fox","jumps",
	"over","the","slow","red","turtle" };
	biggies1440(vs, 4);

	return 0;

}