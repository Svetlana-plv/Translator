#include <iostream>
#include <string>
#include "LexicalAnalysis.h"
#include "Translator.h"


void LexicalAnalysis::LexAnaliysis(std::string infix) {

	if (infix == "") throw "Cannot calculate empty expression";

	for (int i = 0; i < infix.size(); i++) {

		char cur = infix[i];
		if (cur == ' ') continue;

		// check if every symbol is a letter or an operation sign
		bool flage = false;
		flage |= ('0' <= cur && cur <= '9');
		flage |= ('a' <= cur && cur <= 'z');
		flage |= ('A' <= cur && cur <= 'Z');
		flage |= cur == '(';
		flage |= cur == ')';
		flage |= cur == '.';
		flage |= cur == ' ';
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