#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include "Query_base.h"
class StrBlob;

Query operator~(const Query& operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}


Query operator&(const Query& lhs, const Query& rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

Query operator|(const Query& lhs, const Query& rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

std::ostream& operator<<(std::ostream& os, const Query& query)
{
	os << query.rep();
	return os;
}

QueryResult2 NotQuery::eval(const TextQuery2& text) const
{
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<StrBlob::size_type>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult2(rep(), ret_lines, *result.get_file());
}

QueryResult2 AndQuery::eval(const TextQuery2& text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<StrBlob::size_type>>();
	std::set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult2(rep(), ret_lines, *left.get_file());
}

QueryResult2 OrQuery::eval(const TextQuery2& text) const
{

	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines =
		std::make_shared<std::set<StrBlob::size_type>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult2(rep(), ret_lines, *left.get_file());
}
