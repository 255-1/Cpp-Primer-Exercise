#include <iostream>
#include <vector>

using namespace std;

int main938() {

	vector<int> vi;
	while (1) {
		if(vi.size()==vi.capacity())
			cout << "capacity: " << vi.capacity() << endl;
		vi.push_back(0);
	}

	return 0;
}