#include <string>

std::string(&func636(std::string(&arr)[10]))[10];

//���ͱ���
using arr = std::string[10];
arr& func6371(std::string(&arr)[10]);
//β�÷���
auto func6372(std::string(&arr)[10])->std::string(&)[10];
//decltype
//std::string a[3]{ "a","b","c" };
//decltype(a)& func6373(std::string(&arr)[10]);
