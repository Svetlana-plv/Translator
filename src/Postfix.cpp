#include <iostream>
#include <string>
#include "Postfix.h"
#include "stack.h"

std::vector<Term> Postfix::ToPostfix(std::vector<Term> v) {

	std::vector<Term> postfix;
	size_t sz = v.size();
	TStack<Term> stack(sz);

	for (int i = 0; i < sz; i++) {
		if (v[i].type == NUMBER || v[i].type == VARIABLE || v[i].type == CONST) {
			postfix.push_back(v[i]);
		}
		else if (v[i].term == "(") {
			stack.Push(v[i]);
		}
		else if (v[i].type == OPERATION) {

			std::string op = v[i].term;

			if (stack.Empty() || stack.Top().term == "(") {
				stack.Push(v[i]);
			}
			else if (Utility::priority[op] > Utility::priority[stack.Top().term]) {
				stack.Push(v[i]);
			}
			else if (Utility::priority[op] <= Utility::priority[stack.Top().term]) {

				while (!stack.Empty() && (Utility::priority[op] <= Utility::priority[stack.Top().term] || stack.Top().term != "(")) {
					postfix.push_back(stack.Top());
					stack.Pop();
				}
				stack.Push(v[i]);
			}
		}
		else if (v[i].term == ")") {
			while (stack.Top().term != "(") {
				postfix.push_back(stack.Top());
				stack.Pop();
			}
			stack.Pop();
		}
	}

	while (!stack.Empty()) {
		postfix.push_back(stack.Top());
		stack.Pop();
	}

	return postfix;
}