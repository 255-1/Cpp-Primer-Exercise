#include <iterator>
#include <iostream>
#include <fstream>
using namespace std;

void func1033(const string& inputFile,
	const string& oddFile,
	const string& evenFile) {
	ifstream ifs(inputFile);
	ofstream ofs1(oddFile), ofs2(evenFile);
	istream_iterator<int> iii(ifs), eof;
	ostream_iterator<int> oii1(ofs1," "), oii2(ofs2," ");
	while (iii != eof) {
		int i = *iii++;
		if (i & 0x1) {
			oii1 = i;
		}
		else {
			oii2 = i;
		}
	}

}

int main1033() {
	func1033("input1033.txt", "output1033_odd.txt",
		"output1033_even.txt");
	return 0;
}