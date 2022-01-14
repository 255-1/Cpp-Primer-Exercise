#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void elimDups2(vector<string>& vs);

void biggies1019(vector<string>& words,
	vector<string>::size_type sz) {
	elimDups2(words);
	//���ճ�������
	stable_sort(words.begin(), words.end(),
		[](const string& lhs, const string& rhs) {
			return lhs.size() < rhs.size();
		});

	//��ȡ��һ�����ϵĵ�����
	auto wc = stable_partition(words.begin(), words.end(),
		[sz](const string& a) {
			return a.size() < sz;
		});

	//��ӡ
	for_each(wc, words.end(),
		[](const string& s) {
			cout << s << " ";
		});
	cout << endl;
}
int main1019() {
	vector<string> vs{ "the","quick","red","fox","jumps",
	"over","the","slow","red","turtle" };
	biggies1019(vs, 4);

	return 0;
}