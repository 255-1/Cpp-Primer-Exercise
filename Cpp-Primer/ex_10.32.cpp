//#include <iostream>
//#include <iterator>
//#include <algorithm>
//#include <vector>
//#include <fstream>
//#include <numeric>
//#include "Sales_data.h"
//using namespace std;
//
//bool compareIsbn1032(const Sales_data& lhs,
//	const Sales_data& rhs) {
//	return lhs.isbn() < rhs.isbn();
//}
//
//int main1032() {
//	vector<Sales_data> vsi{
//		Sales_data("a",1,1),
//		Sales_data("b",2,2),
//		Sales_data("c",3,3),
//		Sales_data("a",4,4),
//	};
//	sort(vsi.begin(), vsi.end(), compareIsbn1032);
//	for (auto beg = vsi.begin(), end = beg;
//		beg != vsi.end();
//		beg = end) {
//		end = find_if(beg, vsi.end(),
//			[beg](const Sales_data& item) {
//				return item.isbn() != beg->isbn();
//			});
//		if (beg+1 == end) {
//			print(cout, *beg) << "\n";
//			continue;
//		}
//		while (beg != end-1) {
//			beg->combine(*(beg + 1));
//			print(cout, *beg) << "\n";
//			++beg;
//		}
//	}
//	return 0;
//}