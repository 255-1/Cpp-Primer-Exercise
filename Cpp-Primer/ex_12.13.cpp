#include <iostream>
#include <memory>

int main1213()
{
    {
        
    }
    auto sp = std::make_shared<int>();
    auto p = sp.get();
    return 0;
}