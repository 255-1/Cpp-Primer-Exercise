#include <iostream>
using namespace std;
template <typename T> void f(T)
{
    std::cout << "f(T)\n";
}

template <typename T> void f(const T*)
{
    std::cout << "f(const T*)\n";
}
template <typename T> void g(T)
{
    std::cout << "g(T)\n";
}
template <typename T> void g(T*)
{
    std::cout << "g(T*)\n";
}
int main1650()
{
    int i = 42, * p = &i;
    const int ci = 0, * p2 = &ci;

    g(42);    
    g(p);    
    g(ci);    
    g(p2);      
    f(42);    
    f(p);     
    f(ci);    
    f(p2);      

	return 0;
}