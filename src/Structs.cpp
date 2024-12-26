#include <iostream>
#include "Structs.h"


std::set<char> Utility::operations = { '+', '-', '/', '*', '^' };
std::unordered_map<std::string, int> Utility::priority = { {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3} };
std::unordered_map<std::string, float> Utility::constants = { {"pi", 3.1415}, {"e", 2.7182} };
std::unordered_map<std::string, float> Utility::variables = {};
