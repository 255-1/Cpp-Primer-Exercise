#include <iostream>

int main625(int argc, char*argv[]) {
	
	std::cout << std::endl;
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}