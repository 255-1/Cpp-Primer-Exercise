#include "Vec.h"
#include <iostream>
#include <string>
using namespace std;

int main1616()
{
	//Vec<string> vs;
	//test reallocate;
	//cout << vs.capacity() << endl;
	//vs.reallocate();
	//cout << vs.capacity() << endl;
	//vs.reallocate();
	//cout << vs.capacity() << endl;
	
	//test alloc_n_copy
	//Vec<string> tmp({ "a","aa","aaa" });
	//cout << tmp.capacity() << endl;

	//test ������ֵ
	//vs = tmp;
	//cout << vs.capacity() << endl;

	//test �ƶ�����
	//Vec<string> movetest(std::move(tmp));
	//cout << tmp.capacity() << endl;
	//cout << movetest.capacity() << endl;


	//test �б�ֵ
	/*vs = { "a,","a,," };
	cout << vs.capacity() << endl;*/
	
	//test push_back
	//vs.push_back(std::move("asd"));
	//string s = "fgjh";
	//vs.push_back(s);

	


	//test��������
	Vec<int> v1({1,2,3,4,5});
	cout << *(v1.begin()) << endl;
	cout << *(v1.end()-1) << endl;
	Vec<int> v2(v1);

	//test ==���
	cout << (v1 == v2 ? "true" : "false") << endl;
	v1.push_back(6);
	cout << (v1 == v2 ? "true" : "false") << endl;
	return 0;
}