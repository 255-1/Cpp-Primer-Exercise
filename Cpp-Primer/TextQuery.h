#include <vector>
#include <memory>
#include <map>
#include <vector>
#include <set>
#include <string>
#include<fstream>
#include "StrVec.h"

using line_no = std::vector<std::string> ::size_type;
class QueryResult;
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<StrVec> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

};
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<StrVec>f) :
		sought(s), lines(p), file(f) {}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<StrVec>file;
};

