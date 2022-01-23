#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Foo1438 {
public:
	Foo1438(const int i) : target(i) {}
	bool operator()(const string&s) {
		return target == s.size();
	}
private:
	int target;
};
int main1438()
{
	ifstream ifs("input1229.txt");
	string word;
	vector<string> vs;
	while (ifs >> word)
		vs.push_back(word);
	for (int i = 0; i < 10; ++i) {
		cout << count_if(vs.begin(), vs.end(), Foo1438(i)) << endl;;
	}
	
	

	return 0;
}