#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <tuple>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

class TextQuery_17
{
public:
	using line_no = vector<string>::size_type;
	using result_tuple = tuple<string, shared_ptr<set<line_no>>,
		shared_ptr<vector<string>>>;
	TextQuery_17(ifstream& ifs):file(new vector<string>) {
		string text;
		while (getline(ifs, text)) {
			file->push_back(text);
			int n = file->size() - 1;
			istringstream line(text);
			string word;
			while (line >> word) {
				auto& lines = wm[word];
				if (!lines)
					lines.reset(new set<line_no>);
				lines->insert(n);
			}
		}
	}
	//使用tuple得到结果
	result_tuple query(const std::string& sought) {
		static shared_ptr<set<line_no>> noData(new set<line_no>);
		auto loc = wm.find(sought);
		if (loc == wm.end())
			return result_tuple(sought, noData, file);
		else
			return result_tuple(sought, loc->second, file);
	}
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

int main173() 
{
	ifstream ifs("input.txt");
	TextQuery_17 t(ifs);
	TextQuery_17::result_tuple res = t.query("a");
	cout << get<0>(res) << endl;
	shared_ptr<set<TextQuery_17::line_no>> res2 = get<1>(res);
	for (auto& e : *res2)
		cout << e << " ";
	cout << endl;
}