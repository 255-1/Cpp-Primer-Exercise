#include <iostream>

int main8() {
	std::cout << "/*";
	std::cout << "*/";
	//std::cout << /*"*/"*/;  ���Ϸ�
	std::cout << /* "*/"/*"/*"*/;

	return 0;
}