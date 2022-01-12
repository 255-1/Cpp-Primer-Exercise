#include <forward_list>
#include <iostream>

using namespace std;

int main927() {

	forward_list<int> fli {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev = fli.before_begin();
	auto curr = fli.begin();
	while (curr != fli.end()) {
		if (*curr % 2) {
			curr = fli.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}

	for (auto e : fli) cout << e << " ";
	cout << endl;

	return 0;
}