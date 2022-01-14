#include <vector>
#include <iostream>
#include "Sales_data.h"
#include <algorithm>
using namespace std;

int main1017() {
	vector<Sales_data> vs{
		Sales_data("a",1,1),
		Sales_data("b",2,2),
		Sales_data("c",3,3),
		Sales_data("a",2,2)
	};
	sort(vs.begin(), vs.end(), 
		[](const Sales_data &lhs, const Sales_data& rhs) {
			return lhs.isbn() < rhs.isbn();
		});
	for (const auto& e : vs) print(cout, e) << endl;

	return 0;
}