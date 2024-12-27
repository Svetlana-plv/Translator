#include <iostream>
#include <string>
#include "LexicalAnalysis.h"
#include "Translator.h"


void LexicalAnalysis::LexAnaliysis(std::string infix) {

	infix.erase(remove_if(infix.begin(), infix.end(), ::isspace), infix.end());

	if (infix == "") {
		std::string incorrect_symbol = "Cannot calculate empty expression!";
		throw incorrect_symbol;
	}

	for (int i = 0; i < infix.size(); i++) {

		char cur = infix[i];

		// check if every symbol is a letter, number or operation sign
		bool flage = false;
		flage |= ('0' <= cur && cur <= '9');
		flage |= ('a' <= cur && cur <= 'z');
		flage |= ('A' <= cur && cur <= 'Z');
		flage |= cur == '(';
		flage |= cur == ')';
		flage |= cur == '.';
		for (char x : Utility::operations) {
			flage |= (cur == x);
		}
		if (!flage) {
			std::string incorrect_symbol = "Invalid symbol at index ";
			incorrect_symbol += std::to_string(i);
			throw incorrect_symbol;
		}
	}
}