#include <gtest.h>
#include <string>
#include "LexicalAnalysis.h"



TEST(LexicalAnalysis, cant_check_empty_string)
{
	std::string str = "";

	ASSERT_ANY_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, cant_check_string_with_comma_insted_dot)
{
	std::string str = "1,2";

	ASSERT_ANY_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, cant_check_string_with_wrong_symbol)
{
	std::string str = "2=4";

	ASSERT_ANY_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, cant_check_string_with_first_wrong_symbol)
{
	std::string str = "?45";

	ASSERT_ANY_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, cant_check_string_with_last_wrong_symbol)
{
	std::string str = "45:";

	ASSERT_ANY_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_number)
{
	std::string str = "1230";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_float_number)
{
	std::string str = "12.30";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_simple_expression)
{
	std::string str = "2^3";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_simple_expression_with_spaces)
{
	std::string str = " 2 ^  3 ";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_simple_expression_with_float_numbers)
{
	std::string str = ".0+3.45";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str)); 
}

TEST(LexicalAnalysis, can_check_long_expression)
{
	std::string str = "2+4-(3*5+2^10)/9";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_long_expression_with_space)
{
	std::string str = "2  + 4 -( 3*  5+ 2^10 ) / 9";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_long_expression_with_float_numbers)
{
	std::string str = "2.0+4.5-(3*5+2^10)/9";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_expression_with_variables)
{
	std::string str = "a+SUM-2+4.0-c+1";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}

TEST(LexicalAnalysis, can_check_expression_with_constant)
{
	std::string str = "pi+e";

	ASSERT_NO_THROW(LexicalAnalysis::LexAnaliysis(str));
}
