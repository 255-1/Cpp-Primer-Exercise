#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main926() {

	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	list<int> li(begin(ia), end(ia));
	list<int>::iterator it = li.begin();
	while (it != li.end()) {
		if (*it & 0x1) {
			it = li.erase(it);
		}
		else {
			++it;
		}
	}
	for (auto e : li) cout << e << " ";
	cout << endl;

	vector<int> vi(begin(ia), end(ia));
	vector<int>::iterator it2 = vi.begin();
	while (it2 != vi.end()) {
		if (*it2 & 0x1) {
			++it2;
		}
		else {
			it2 = vi.erase(it2);
		}
	}

	
	for (auto e : vi) cout << e << " ";
	cout << endl;
	return 0;
}