#include <vector>
#include <iostream>
#include "Sales_data.h"
#include <algorithm>
using namespace std;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}


int main1012() {
	vector<Sales_data> vs{
		Sales_data("a",1,1),
		Sales_data("b",2,2),
		Sales_data("c",3,3),
		Sales_data("a",2,2)
	};
	sort(vs.begin(), vs.end(), compareIsbn);
	//for (const auto& e : vs) print(cout,e) << endl;

	return 0;
}