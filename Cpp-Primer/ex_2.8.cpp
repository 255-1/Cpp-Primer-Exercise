#include <iostream>
#include <bitset>

int _;
int ___t__e_s__t_____;
int _Test;

int main28()
{
	//输出"2M"
	std::cout << "\062\115\n";
	//输出"2"再输出制表符再输出"M"然后换行符
	std::cout << '\062' << "\t" << "\115" << "\n";

	std::bitset<4> value("1011");
	std::cout << compl value;
	return 0;
}