#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Structs.h"
#include "stack.h"

class Calculator {
public:
	static void GetVariable();

	static void Lex_Analisis(std::string str);

	static float Calculating(std::vector<Term> v);

};