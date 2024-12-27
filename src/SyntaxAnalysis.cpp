#include "SyntaxAnalysis.h"
#include <set>

void SyntaxAnalysis::Analysis(std::vector<Term> v) {

	int status = 0;
	int count_bracket = 0;

	size_t sz = v.size();

	for (int i = 0; i < sz; i++) {
		switch (status)
		{
		case 0:
			if (v[i].type == VARIABLE || v[i].type == CONST || v[i].type == NUMBER) status = 1;
			else if (v[i].type == BRACKET) {
				if (v[i].term == "(") {
					status = 2;
					count_bracket++;
				}
				if (v[i].term == ")") {
					std::string incorrect_symbol = "Incorrect breacket!";
					throw incorrect_symbol;
				}
			}
			else {
				std::string incorrect_symbol = "Operation cannot be at first place!";
				throw incorrect_symbol;
			}
			break;
		case 1:
			if (v[i].type == OPERATION) status = 4;
			else if (v[i].type == BRACKET) {
				if (v[i].term == ")") {
					status = 3;
					count_bracket--;
				}
				if (v[i].term == "(" || count_bracket<0) {
					std::string incorrect_symbol = "Incorrect breacket!";
					throw incorrect_symbol;
				}
			}
			else {
				std::string incorrect_symbol = "Operator cannot stand after operator!";
				throw incorrect_symbol;
			}
			break;
		case 2:
			if (v[i].type == VARIABLE || v[i].type == CONST || v[i].type == NUMBER) status = 1;
			else if (v[i].type == BRACKET) {
				if (v[i].term == "(") {
					status = 2;
					count_bracket++;
				}
				else if (v[i].term == ")") {
					std::string incorrect_symbol = "Incorrect breacket!";
					throw incorrect_symbol;
				}
			}
			else {
				std::string incorrect_symbol = "After opening bracket can only be an operand!";
				throw incorrect_symbol;
			}
			break;
		case 3:
			if (v[i].type == OPERATION) status = 4;
			else if (v[i].type == BRACKET) {
				if (v[i].term == ")") {
					status = 3;
					count_bracket--;
				}
				if (v[i].term == "(" || count_bracket < 0) {
					std::string incorrect_symbol = "Incorrect breacket!";
					throw incorrect_symbol;
				}
			}
			else {
				std::string incorrect_symbol = "After closing bracket can only be an operation!";
				throw incorrect_symbol;
			}
			break;
		case 4:
			if (v[i].type == VARIABLE || v[i].type == CONST || v[i].type == NUMBER) status = 1;
			else if (v[i].type == BRACKET) {
				if (v[i].term == "(") {
					status = 2;
					count_bracket++;
				}
				else if (v[i].term == ")") {
					std::string incorrect_symbol = "Incorrect breacket!";
					throw incorrect_symbol;
				}
			}
			else {
				std::string incorrect_symbol = "After operation can only be an operator or opening bracket!";
				throw incorrect_symbol;
			}
			break;
		default:
			break;
		}
	}
	if (status==2) {
		std::string incorrect_symbol = "Expression cannnot end with a bracket!";
		throw incorrect_symbol;
	}
	if (status == 4) {
		std::string incorrect_symbol = "Expression cannnot end with a operation!";
		throw incorrect_symbol;
	}
	if (count_bracket != 0) {
		std::string incorrect_symbol = "The number of breackets doesn't match!";
		throw incorrect_symbol;
	}
}

std::vector<Term> SyntaxAnalysis::ToTerms(std::string infix) {
	std::vector<Term> terms;
	int i = 0;
	while (i < infix.size()) {

		if (infix[i] == '(' || infix[i] == ')') {
			std::string elem;
			elem += infix[i];
			terms.push_back(Term(elem, BRACKET));
			i++;
			continue;
		}
		else if (Utility::operations.find(infix[i]) != Utility::operations.end()) {
			std::string elem;
			elem += infix[i];
			terms.push_back(Term(elem, OPERATION));
			i++;
			continue;
		}
		else if (('0' <= infix[i] && infix[i] <= '9') || infix[i] == '.') {
			std::string number;
			if (infix[i] == '0' && i < infix.size() && '1' <= infix[i + 1] && infix[i + 1] <= '9') {
				std::string incorrect_symbol = "The number cannot start from zero! Invalid symbol at index ";
				incorrect_symbol += std::to_string(i);
				throw incorrect_symbol;
			}

			int point_counter = 0;
			while (i < infix.size() && '0' <= infix[i] && infix[i] <= '9' || infix[i] == '.') {
				number.push_back(infix[i]);
				if (infix[i] == '.') point_counter++;
				i++;
			}
			if (point_counter > 1) {
				std::string error = "A real number is entered incorrectly!";
				throw error;
			}
			if (point_counter == 1 && number.size() == 1) {
				std::string error = "Operator cannot be point!";
				throw error;
			}

			terms.push_back(Term(number, NUMBER));
			continue;
		}
		else if ('a' <= infix[i] && infix[i] <= 'z' || 'A' <= infix[i] && infix[i] <= 'Z') {

			std::string var;
			var.push_back(infix[i]);
			i++;

			while (i < infix.size() && 'a' <= infix[i] && infix[i] <= 'z' || 'A' <= infix[i] && infix[i] <= 'Z' || '0' <= infix[i] && infix[i] <= '9') {
				var.push_back(infix[i]);
				i++;
			}

			bool flag = true;
			for (auto x : Utility::constants) {
				if (var == x.first) {
					terms.push_back(Term(var, CONST));
					flag = false;
					break;
				}
			}
			if (flag) {
				Utility::variables.insert({ var, 0 });
				terms.push_back(Term(var, VARIABLE));
			}
		}
	}
	return terms;
}