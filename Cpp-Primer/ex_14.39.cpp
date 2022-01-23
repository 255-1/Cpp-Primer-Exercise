#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Foo1439 {
public:
	Foo1439(const int l, const int h) : low(l),high(h) {}
	bool operator()(const string& s) {
		return s.size() >= low && s.size() <= high;
	}
private:
	int low, high;
};
int main1439()
{
	ifstream ifs("input1229.txt");
	string word;
	vector<string> vs;
	while (ifs >> word)
		vs.push_back(word);
	cout << count_if(vs.begin(), vs.end(), Foo1439(1,9)) << endl;;
	cout << count_if(vs.begin(), vs.end(), Foo1439(10,INT_MAX)) << endl;;



	return 0;
}