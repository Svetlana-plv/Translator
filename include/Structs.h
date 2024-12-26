#pragma once
#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>

struct Utility{
public:
	//inline static const std::set<std::string> operations = { '+', '-', '/', '*', '^' };
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
private:



public:
	std::string term;
	termtype type;
	Term():term(""), type(NONTYPE) {}
	Term(std::string term_, termtype type_): term(term_), type(type_){}
};