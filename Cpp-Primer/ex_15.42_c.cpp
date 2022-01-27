#include "Query_base.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs("input159.txt");
	TextQuery2 t(ifs);
	Query q = ~Query("fiery");
	auto ret = q.eval(t);
	print2(cout, ret, 4, 7);

	return 0;
}