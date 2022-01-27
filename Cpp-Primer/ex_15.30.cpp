#include "Basket.h"
#include <iostream>
using namespace std;

int main1530() 
{ 
    Basket basket;
    basket.add_item(Bulk_quote("a",1,1,.5));
    basket.add_item(Bulk_quote("b",2,2,.5));
    basket.add_item(Quote("c",1));
    basket.add_item(Quote("d",2));
    basket.total_receipt(cout);

    return 0;
}
