#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Structs.h"
#include "stack.h"

class SyntaxAnalysis {
public:

	static void Analysis(std::vector<Term> v);

	static std::vector<Term> ToTerms(std::string infix);
};