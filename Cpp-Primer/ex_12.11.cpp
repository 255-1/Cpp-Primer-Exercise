#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main1211()
{
    std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p.get()));
    return 0;
}