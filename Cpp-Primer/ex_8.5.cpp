#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void func85(const std::string& fileName) {
	std::ifstream ifs(fileName);
	std::vector<std::string> vs;
	if (ifs) {
		std::string s;
		while (ifs>>s) {
			vs.push_back(s);
		}
	}

	for (std::string s : vs) {
		std::cout << s << std::endl;
	}
	ifs.close();
}

int main85() {

	func85("input.txt");

	return 0;
}