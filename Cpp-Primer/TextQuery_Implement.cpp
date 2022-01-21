#include "TextQuery.h"
#include <vector>
#include <memory>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
TextQuery::TextQuery(std::ifstream& is) :file(new StrVec) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word, ret;
		while (line >> word) {
			for (auto& c : word)
				c = tolower(c);
			remove_copy_if(word.begin(), word.end(), back_inserter(ret), ispunct);
			auto& lines = wm[ret];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult
TextQuery::query(const std::string& sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream& 
print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " times"<< endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin()+num) << endl;
	return os;
}
