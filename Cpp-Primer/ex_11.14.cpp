#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Families {
public:
	using Child = pair<string, string>;
	using Children = vector<Child>;
	using Data = map<string, Children>;
	void add(string const& last_name,
		string const& first_name,
		string birthday) {
		_data[last_name].emplace_back(first_name, birthday);
	}
	void print() const {
		for (auto const& e : _data) {
			cout << e.first << ":\n";
			for (auto const& const child : e.second)
				cout << child.first << " " << child.second << endl;
			cout << endl;
		}
	}
private:
	Data _data;

};

int main1114()
{
	Families families;
	auto msg = "Please enter last name, first name and birthday:\n";
	for (string l, f, b; cout << msg, cin >> l >> f >> b; families.add(l, f, b));
	families.print();

	return 0;
}