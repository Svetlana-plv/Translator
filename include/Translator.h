#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "stack.h"
#include "Structs.h"


class Translator {

private:
	std::string infix;
	std::vector<Term> postfix;

public:

	

	//Translator(std::string user_infix) : infix(user_infix) {}

	std::string get_infix();
	std::vector<Term> get_postfix();

	void execute();

private:

	void set_infix(std::string str);
	void set_postfix(std::vector<Term> str);
};
