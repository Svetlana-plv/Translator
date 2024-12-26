#include "Calculator.h"


void Calculator::GetVariable() {
	try {
		std::cout << "Enter the values of variables:"<< std::endl;
		for (auto x : Utility::variables) {
			std::cout << x.first << " = ";
			std::string str;
			std::getline(std::cin, str);
			Lex_Analisis(str);
			Utility::variables[x.first] = stof(str);
		}
	}
	catch (std::string error_message) {
		std::cout << error_message << std::endl;
	}
}

void Calculator::Lex_Analisis(std::string str) {
	if (str == "") throw "You enter empty string! Try again!";
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
	if (str.size()>0 && !('1' <= str[0] && str[0] <= '9' || str[0] == '.')) {
		std::string incorrect_symbol = "Incorrect number! Try again!";
		throw incorrect_symbol;
	}
	int point_counter = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[0] == '.') point_counter++;
		char cur = str[i];
		bool flage = false;
		flage |= ('0' <= cur && cur <= '9');
		flage |= cur == '.';
		if (!flage || point_counter>1) {
			std::string incorrect_symbol = "Incorrect number! Try again!";
			incorrect_symbol += std::to_string(i);
			throw incorrect_symbol;
		}
	}
}

float Calculator::Calculating(std::vector<Term> v) {
	if (!Utility::variables.empty()) GetVariable();
	size_t sz = v.size();
	TStack<float> stack(sz);
	for (size_t i = 0; i < sz; i++) {
		Term elem = v[i];
		if (elem.type == NUMBER) stack.Push(stof(elem.term));
		else if (elem.type == CONST) {
			float  num = Utility::constants[elem.term];
			stack.Push(num);
		}
		else if (elem.type == VARIABLE) {
			float  num = Utility::variables[elem.term];
			stack.Push(num);
		}
		else if (elem.type == OPERATION) {
			float right = stack.Top();
			stack.Pop();
			float left = stack.Top();
			stack.Pop();
			switch (elem.term[0]) {
				case '+':
					stack.Push(left + right);
					break;
				case '-':
					stack.Push(left - right);
					break;
				case '*':
					stack.Push(left * right);
					break;
				case '/':
					if (right == 0.0) { 
						std::string incorrect_symbol = "Cant devide by zero!";
						throw incorrect_symbol;
					}
					stack.Push(left / right);
					break;
				case '^':
					stack.Push(pow(left, right));
					break;
				default:
					break;

			}
			
		}
	}
	Utility::variables.clear();
	return stack.Top();
}