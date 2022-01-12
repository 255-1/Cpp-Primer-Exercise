#include <iostream>
#include <cstring>

using namespace std;

const char cstr1[] = "Hello";
const char cstr2[] = "world";

constexpr size_t constexpr_strlen(const char* s) {
	return sizeof(s) / sizeof(*s);
}


constexpr size_t merge_size(const char* cs1, const char* cs2) {
	return constexpr_strlen(cstr1) + constexpr_strlen(cstr2)+ constexpr_strlen(" ")+1;
}

int main340() {

	char cstr3[merge_size(cstr1, cstr2)];
	strcpy_s(cstr3, cstr1);
	strcat_s(cstr3, " ");
	strcat_s(cstr3, cstr2);
	cout << cstr3 << endl;
	return 0;
}