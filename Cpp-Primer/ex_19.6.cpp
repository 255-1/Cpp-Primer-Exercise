#include "Query_base.h"
#include <string>
#include <iostream>
using namespace std;
int main196()
{
	Query_base* qb = new WordQuery("aa");
	AndQuery* aq = dynamic_cast<AndQuery*>(qb);
	cout << typeid(*qb).name() << endl;
	cout << typeid(qb).name()<< endl;
	cout << typeid(*aq).name() << endl;
	cout << typeid(aq).name() << endl;
	return 0;
}