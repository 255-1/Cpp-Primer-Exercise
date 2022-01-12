#include <iostream>

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending="s") {
	return (ctr > 1) ? word + ending : word;
}

int main642() {

	std::string s1 = "success";
	std::string s2 = "failure";
	std::cout << make_plural(2, s1) << std::endl;
	std::cout << make_plural(2, s2) << std::endl;
	return 0;
}