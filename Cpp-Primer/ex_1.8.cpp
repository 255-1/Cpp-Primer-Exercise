#include <iostream>

int main8() {
	std::cout << "/*";
	std::cout << "*/";
	//std::cout << /*"*/"*/;  ²»ºÏ·¨
	std::cout << /* "*/"/*"/*"*/;

	return 0;
}