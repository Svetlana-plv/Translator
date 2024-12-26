#include <gtest.h>
#include <string>
#include "Postfix.h"
#include "SyntaxAnalysis.h"




TEST(Postfix, can_transform_simple_expression)
{
	std::string str = "a+b";
	std::vector<Term> v;
	std::string postf;

	v = SyntaxAnalysis::ToTerms(str);
	std::vector<Term> postfix= Postfix::ToPostfix(v);;
	

	for (int i = 0; i < postfix.size(); i++) {
		postf += static_cast<std::string>(postfix[i].term);
	}

	EXPECT_EQ("ab+", postf);
}

TEST(Postfix, can_transform_simple_expression_with_different_priority)
{
	std::string str = "5+6^2";
	std::vector<Term> v;
	std::string postf;

	v = SyntaxAnalysis::ToTerms(str);
	std::vector<Term> postfix = Postfix::ToPostfix(v);;


	for (int i = 0; i < postfix.size(); i++) {
		postf += static_cast<std::string>(postfix[i].term);
	}

	EXPECT_EQ("562^+", postf);
}

TEST(Postfix, can_transform_simple_expression_with_bracket)
{
	std::string str = "(5+6)^2";
	std::vector<Term> v;
	std::string postf;

	v = SyntaxAnalysis::ToTerms(str);
	std::vector<Term> postfix = Postfix::ToPostfix(v);;


	for (int i = 0; i < postfix.size(); i++) {
		postf += static_cast<std::string>(postfix[i].term);
	}

	EXPECT_EQ("56+2^", postf);
}

TEST(Postfix, can_transform_long_expression)
{
	std::string str = "5*8*(2+9)+(7-5+8-9*(5*5)+5)";
	std::vector<Term> v;
	std::string postf;

	v = SyntaxAnalysis::ToTerms(str);
	std::vector<Term> postfix = Postfix::ToPostfix(v);;


	for (int i = 0; i < postfix.size(); i++) {
		postf += static_cast<std::string>(postfix[i].term);
	}

	EXPECT_EQ("58*29+*75-8+955**-5++", postf);
}

TEST(Postfix, can_transform_expressinon_from_lection)
{
	std::string str = "(1+2*3)*(4/5-6)";
	std::vector<Term> v;
	std::string postf;

	v = SyntaxAnalysis::ToTerms(str);
	std::vector<Term> postfix = Postfix::ToPostfix(v);;


	for (int i = 0; i < postfix.size(); i++) {
		postf += static_cast<std::string>(postfix[i].term);
	}

	EXPECT_EQ("123*+45/6-*", postf);
}



