#include <map>
#include <string>
#include <iostream>
using namespace std;

int main1123() {

	multimap<string, string> mss;
	for (string lname, cname;
		cin >> cname >> lname;
		mss.emplace(lname, cname));
	for (const auto& e : mss) {
		cout << e.second << " " << e.first << endl;
	}

	return 0;
}