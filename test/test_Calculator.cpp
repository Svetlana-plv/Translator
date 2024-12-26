#include <gtest.h>
#include <string>
#include "Calculator.h"
#include "Postfix.h"
#include "SyntaxAnalysis.h"

TEST(Calculator, cant_devide_by_zero)
{
	std::string str = "1/0";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);

	ASSERT_ANY_THROW(Calculator::Calculating(v));
}

TEST(Calculator, cant_devide_by_implicit_zero)
{
	std::string str = "2/(1-1)";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);

	ASSERT_ANY_THROW(Calculator::Calculating(v));
}

TEST(Calculator, can_calculate_simple_add)
{
	std::string str = "8+9";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 17);
}

TEST(Calculator, can_calculate_simple_sub)
{
	std::string str = "8-9";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, -1);
}

TEST(Calculator, can_calculate_simple_mul)
{
	std::string str = "8*9";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 72);
}

TEST(Calculator, can_calculate_simple_div)
{
	std::string str = "1/2";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 0.5);
}

TEST(Calculator, can_calculate_simple_pow)
{
	std::string str = "2^3";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 8);
}

TEST(Calculator, can_calculate_ex1)
{
	std::string str = "2*(1+3+5)";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 18);
}

TEST(Calculator, can_calculate_ex2)
{
	std::string str = "2^(1+3+5)";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 512);
}

TEST(Calculator, can_calculate_crash_test_from_elena)
{
	std::string str = "(1/2+2)*3-1*(2-3*4)+1";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 18.5);
}

TEST(Calculator, can_calculate_test_from_lection)
{
	std::string str = "(1+2*3)*(4-6)/8";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, -1.75);
}

TEST(Calculator, can_calculate_my_test)
{
	std::string str = "5*8*(2+9)+(7-5+8-9*(5*5)+5)";
	std::vector<Term> v = SyntaxAnalysis::ToTerms(str);
	v = Postfix::ToPostfix(v);
	float res = Calculator::Calculating(v);

	EXPECT_EQ(res, 230);
}