#include <vector>
#include <memory>
#include <map>
#include <vector>
#include <set>
#include <string>
#include<fstream>
#include "StrBlob.h"

class QueryResult2;
class TextQuery2 {
public:
	using line_no = std::vector<std::string> ::size_type;
	TextQuery2(std::ifstream&);
	QueryResult2 query(const std::string&) const;
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<StrBlob::size_type>>> wm;
};

class QueryResult2 {
	//friend std::ostream& print2(std::ostream&, const QueryResult2&);
	friend std::ostream& print2(std::ostream&, QueryResult2);
public:
	using ResultIter = std::set<StrBlob::size_type>::iterator;
	QueryResult2()=default;
	QueryResult2(std::string s,
		std::shared_ptr<std::set<StrBlob::size_type>>p,
		StrBlob f) :
		sought(s), lines(p), file(f) {}
	ResultIter begin() const { return lines->begin(); }
	ResultIter end() const { return lines->end(); }
	std::shared_ptr<StrBlob> get_file() const { return std::make_shared<StrBlob>(file); }
private:
	std::string sought;
	std::shared_ptr<std::set<StrBlob::size_type>> lines;
	StrBlob file;
};

//std::ostream& print2(std::ostream&, const QueryResult2&);
std::ostream& print2(std::ostream&, QueryResult2);