#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct PeopleInfo
{
	string name;
	vector<string> phone;
};

bool valid(const string& num) {
	return false;
}

string format(const string& num) {
	return num;
}

int main813() {
	//∂¡»Î
	string line, word;
	vector<PeopleInfo> people;
	ifstream ifs("input.txt");
	while (getline(ifs, line)) {
		PeopleInfo info;
		istringstream record(line);
		while (record >> word)
			info.phone.push_back(word);
		people.push_back(info);
	}
	// ‰≥ˆ
	for (const auto& entry : people) {
		ostringstream formatted, badNums;
		for (const auto& nums : entry.phone) {
			if (!valid(nums)) {
				badNums << " " << nums;
			}
			else {
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty())
			std::cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << "invalid number(s)"
			<< badNums.str() << endl;
	}

	return 0;

}