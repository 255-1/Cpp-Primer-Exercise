#include <iostream>

inline bool isShorter(const std::string& s1, const std::string& s2) {
	return s1.size() < s2.size();
}

int main644() {

	std::cout << isShorter("a","bb") <<  std::endl;	

	return 0;
}