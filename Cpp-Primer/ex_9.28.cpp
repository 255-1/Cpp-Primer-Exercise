#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void func928(forward_list<string>& fls,
	const string& s1, const string& s2) {
	auto curr = fls.begin();
	while (curr != fls.end()) {
		if (*curr == s1) {
			curr = fls.insert_after(curr,s2);
		}										
		else {
			++curr;
		}
	}
}

int main928() {
	forward_list<string> fls{ "abc","def","ghi","def","def"};
	func928(fls, "def", "111");
	for (auto e : fls) cout << e << " ";
	cout << endl;


	return 0;
}