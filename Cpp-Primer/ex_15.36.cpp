#include "Query_base.h"
#include <iostream>
using namespace std;

int main1536()
{

	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << "cout------------------"<<endl;
	cout << q.rep();
	return 0;
}