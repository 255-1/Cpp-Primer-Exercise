#include "StrBlob.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main1432()
{
    StrBlob sb{ "hello", "world" };
    StrBlobPtr iter(sb);
    StrBlobPtr_pointer p(&iter);
    std::cout << p->deref() << std::endl;
    return 0;
}