#include "Sales_data.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main1662()
{
	unordered_set<Sales_data> SDset;
	SDset.insert(Sales_data("a", 1, 1));
	SDset.insert(Sales_data("b", 2, 2));
	copy(SDset.begin(), SDset.end(), ostream_iterator<Sales_data>(cout, "\n"));
	return 0;
}