#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
void elimDups2(vector<string>& vs);

bool check_size1025(const string& s, size_t sz) {
	return s.size() < sz;
}

void biggies1025(vector<string>& words,
	vector<string>::size_type sz) {
	elimDups2(words);
	//���ճ�������
	stable_sort(words.begin(), words.end(),
		[](const string& lhs, const string& rhs) {
			return lhs.size() < rhs.size();
		});

	//��ȡ��һ�����ϵĵ�����
	auto wc = partition(words.begin(), words.end(),
		bind(check_size1025,std::placeholders::_1, sz));

	//��ӡ
	for_each(wc, words.end(),
		[](const string& s) {
			cout << s << " ";
		});
	cout << endl;
}
int main1025() {
	vector<string> vs{ "the","quick","red","fox","jumps",
	"over","the","slow","red","turtle" };
	biggies1025(vs, 4);

	return 0;
}