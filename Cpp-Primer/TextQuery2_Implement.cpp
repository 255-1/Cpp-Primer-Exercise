#include "TextQuery2.h"
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
TextQuery2::TextQuery2(std::ifstream& is){
	string text;
	while (getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			for (auto& c : word)
				c = tolower(c);
			//remove_copy_if(word.begin(), word.end(), back_inserter(ret), ispunct);
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new set<StrBlob::size_type>);
			lines->insert(n);
		}
	}
}

QueryResult2
TextQuery2::query(const std::string& sought) const {
	static shared_ptr<set<StrBlob::size_type>> nodata(new set<StrBlob::size_type>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult2(sought, nodata, file);
	else
		return QueryResult2(sought, loc->second, file);
}

//std::ostream&
//print2(std::ostream& os, const QueryResult2& qr) {
//	os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
//	for (auto it = qr.begin(); it != qr.end(); ++it) {
//		ConstStrBlobPtr p(*qr.get_file(), *it);
//		os << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
//	}
//	return os;
//}

std::ostream&
print2(std::ostream& os, QueryResult2 qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file.begin() + num) << endl;
	}
	return os;
}

std::ostream&
print2(std::ostream& os, QueryResult2 qr, size_t lo, size_t hi) {
	os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
	for (auto num : *qr.lines) {
		if(num >= lo && num <= hi)
			os << "\t(line " << num + 1 << ") "<< *(qr.file.begin() + num) << endl;
	}
	return os;
}
