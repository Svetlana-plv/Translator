#pragma once
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>

struct Utility{
public:
	static std::set<char> operations;
	static std::unordered_map<std::string, int> priority;
	static std::unordered_map<std::string, float> constants;
	static std::unordered_map<std::string, float> variables;
};

enum termtype {
	NUMBER,
	OPERATION,
	VARIABLE,
	CONST,
	BRACKET,
	NONTYPE
};

class Term {
public:
	std::string term;
	termtype type;
	Term():term(""), type(NONTYPE) {}
	Term(std::string term_, termtype type_): term(term_), type(type_){}
};