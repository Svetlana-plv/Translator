#include <gtest.h>
#include <string>
#include "SyntaxAnalysis.h"



TEST(ToTerms, cant_split_to_terms_number_with_several_dots)
{
	std::string str = "1.1.3";

	ASSERT_ANY_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, cant_split_to_terms_number_with_several_dots_in_expression)
{
	std::string str = "4+1.1.3-45";

	ASSERT_ANY_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, can_split_to_terms_float_number)
{
	std::string str = "1.0";

	ASSERT_NO_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, cant_split_to_terms_number_strted_from_zero)
{
	std::string str = "0123";

	ASSERT_ANY_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, cant_split_to_terms_float_number_strted_from_zero)
{
	std::string str = "01.67";

	ASSERT_ANY_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, can_split_to_terms_float_number_started_from_one_zero)
{
	std::string str = "0.2";

	ASSERT_NO_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, cant_split_to_terms_number_strted_from_zero_in_expression)
{
	std::string str = "2^3-4*0123+5";

	ASSERT_ANY_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, cant_split_to_terms_when_point_is_operator)
{
	std::string str = "2+.+3";

	ASSERT_ANY_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, can_split_to_terms_float_number_with_first_point)
{
	std::string str = "2+.4";

	ASSERT_NO_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, cant_split_to_terms_float_number_with_last_point)
{
	std::string str = "2+4.";

	ASSERT_NO_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(ToTerms, can_split_to_terms_expression_with_a_lot_of_spaces)
{
	std::string str = " 5.5 - 5 * 46-7 + ( 3^2* 9)    -4 + 5  ";

	ASSERT_NO_THROW(SyntaxAnalysis::ToTerms(str));
}

TEST(Analysis, cant_started_from_close_bracket)
{
	std::string str = ")+4-5";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, cant_started_from_operation)
{
	std::string str = "+4-5";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, open_bracket_cant_stand_after_close)
{
	std::string str = "1-(2+3)(5-4)";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, open_bracket_cant_stend_near_to_close)
{
	std::string str = "1-()+2";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, open_brackets_more_then_close)
{
	std::string str = "3+(2+5";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, close_brackets_more_then_open)
{
	std::string str = "3+(2+5))";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, operands_cant_stand_near)
{
	std::string str = "1+2a";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, operations_cant_stand_near)
{
	std::string str = "1+-5";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, operations_cant_stand_arter_bracket)
{
	std::string str = "5-(+5-1)";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, expression_cant_end_with_open_bracket)
{
	std::string str = "5+5-(";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}

TEST(Analysis, expression_cant_end_with_operation)
{
	std::string str = "5+5-";
	std::vector<Term> v;

	v = SyntaxAnalysis::ToTerms(str);

	ASSERT_ANY_THROW(SyntaxAnalysis::Analysis(v));
}