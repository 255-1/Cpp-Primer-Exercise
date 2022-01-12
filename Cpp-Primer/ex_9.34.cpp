#include <vector>
#include <iostream>

using namespace std;

int main934() {

	vector<int> vi{ 0,1,2,3,4,5,6 };
	auto iter = vi.begin();
	while (iter != vi.end())
		if (*iter % 2)
			iter = vi.insert(iter, *iter), iter += 2;
		else
			++iter;
	for (auto e : vi) cout << e << " ";
	cout << endl;


	return 0;
}