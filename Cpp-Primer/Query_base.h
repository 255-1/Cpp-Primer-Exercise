#pragma once
#include <string>
#include <iostream>
#include "TextQuery2.h"
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery2::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult2 eval(const TextQuery2&)const = 0;
	virtual std::string rep() const = 0;
};
class WordQuery : public Query_base
{
	friend class Query;
public:
	WordQuery(const std::string& s) :query_word(s) {
		std::cout << "WordQuery构造,s=" + s << std::endl;
	}
	QueryResult2 eval(const TextQuery2& t)const override
	{
		return t.query(query_word);
	}
	std::string rep() const override
	{
		return query_word;
	}

	std::string query_word;
};


class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string& s):q(new WordQuery(s)) {
		std::cout << "Query构造,s=" + s << std::endl;
	}
	QueryResult2 eval(const TextQuery2& t) const
	{
		return q->eval(t);
	}
	std::string rep() const
	{
		//std::cout << q->rep() << std::endl;
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) :
		q(query) {}
	std::shared_ptr<Query_base> q;
};

Query operator~(const Query&);
Query operator|(const Query&, const Query&);
Query operator&(const Query&, const Query&);
std::ostream& operator<<(std::ostream& os, const Query& query);



class NotQuery : public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query& q) :query(q) {
		std::cout << "NotQuery构造" << std::endl;
	}
	QueryResult2 eval(const TextQuery2& t) const override;
	std::string rep() const override
	{
		std::cout << "NotQuery.rep()" << std::endl;
		return "~(" + query.rep() + ")";
	}
	Query query;

};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query& l, const Query& r, std::string s) :
		lhs(l), rhs(r), opSym(s) {
		std::cout << "BinaryQuery构造" << std::endl;
	}
	std::string rep() const override {
		/*std::cout <<("(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")")<< std::endl;*/
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	std::string opSym;
	Query lhs, rhs;
};

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "&") {
		std::cout << "AndQuery构造" << std::endl;
	}
	QueryResult2 eval(const TextQuery2&)const;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "|") {
		std::cout << "OrQuery构造" << std::endl;
	}
	QueryResult2 eval(const TextQuery2&)const;
};