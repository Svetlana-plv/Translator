#include <iostream>
#include <string>
#include "Translator.h"
#include "LexicalAnalysis.h"
#include "Postfix.h"
#include "Calculator.h"
#include "SyntaxAnalysis.h"

std::string Translator::get_infix() { return infix; }

std::vector<Term> Translator::get_postfix() { return postfix; }

void Translator::set_infix(std::string str) { infix = str; }

void Translator::set_postfix(std::vector<Term> str) { postfix = str; }

void Translator::execute() {
	while ( true) {
		try {
			std::cout << "Input an arithmetic expression!" << std::endl;
			std::string str;
			std::getline(std::cin, str);

			this->infix = str;
			LexicalAnalysis::LexAnaliysis(this->infix);
			std::cout << this->infix << std::endl;

			std::vector<Term> v;
			v = SyntaxAnalysis::ToTerms(this->infix);

			SyntaxAnalysis::Analisis(v);

			for (int i = 0; i < v.size(); i++) {
				std::cout << "term "<< i << ":" << v[i].type << " " << v[i].term << std::endl;
			}



			//std::cout << Utility::priority["="] << std::endl;
			this->postfix=Postfix::ToPostfix(v);
			std::cout << std::endl;
			std::string postf;
			for (int i = 0; i < postfix.size(); i++) {
				std::cout << "term " << i << ":" << postfix[i].type << " " << postfix[i].term << std::endl;
				postf += static_cast<std::string>(postfix[i].term);
			}
			std::cout << postf << std::endl;

			float result;
			result = Calculator::Calculating(this->postfix);
			std::cout << "Result: " << result << std::endl;
			std::cout << std::endl;
			
		}
		catch(std::string error_message) {
			std::cout << std::endl;
			std::cout << error_message << std::endl;
			std::cout << std::endl;
		}

	}
}
