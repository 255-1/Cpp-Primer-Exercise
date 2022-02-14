#include <string>

std::string(&func636(std::string(&arr)[10]))[10];

//类型别名
using arr = std::string[10];
arr& func6371(std::string(&arr)[10]);
//尾置返回
auto func6372(std::string(&arr)[10])->std::string(&)[10];
//decltype
//std::string a[3]{ "a","b","c" };
//decltype(a)& func6373(std::string(&arr)[10]);
