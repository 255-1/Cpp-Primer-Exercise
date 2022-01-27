#include "Query_base.h"
#include <iostream>
#include <fstream>
using namespace std;

int main1539()
{
	ifstream ifs("input159.txt");
	TextQuery2 t(ifs);
	//Query q = Query("fiery") & Query("bird,");
	Query q = Query("fiery") & Query("bird,") | Query("wind");
	
	print2(cout,q.eval(t));

	return 0;
}