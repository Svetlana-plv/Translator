#pragma once
#include <vector>
#include <string>
#include "Structs.h"

class Postfix {
public:

	static std::vector<Term> ToPostfix(std::vector<Term> v);

};

