#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void elimDups1042(list<string>& words) {
	words.sort();
	words.unique();
}

int main() {
	list<string> ls{ "a","aa","aaa","asadas" };
	elimDups1042(ls);
	for (const auto& e : ls) cout << e << " ";
	cout << endl;

	return 0;
}