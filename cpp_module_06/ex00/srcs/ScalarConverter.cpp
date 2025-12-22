/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:20:14 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/31 19:20:15 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* default constructor */
ScalarConverter::ScalarConverter()
{
}

/* argumented constructor */
// ScalarConverter::ScalarConverter(void)
// {
// }

/* copy constructor */
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	static_cast<void>(other);
}

/* copy assignment constructor */
ScalarConverter &ScalarConverter::operator = (const ScalarConverter &other)
{
	static_cast<void>(other);
	return (*this);
}

/* deconstructor */
ScalarConverter::~ScalarConverter()
{

}

static types checkLiteralType(const std::string &literal)
{
	if (literal.empty())
		return (INT);
	if (literal.length() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'')
		return (CHAR);
	if (literal.compare("+inff") == 0 || literal.compare("-inff") == 0 || literal.compare("nanf") == 0)
		return (FLOAT);
	if (literal.compare("+inf") == 0 || literal.compare("-inf") == 0 || literal.compare("nan") == 0)
		return (DOUBLE);
	if (literal.find('.') != std::string::npos)
	{
		if (literal.at(literal.length() - 1) == 'f')
			return (FLOAT);
		return (DOUBLE);
	}
	return (INT);
}

static bool isInSet(char c, const std::string &set)
{
	return (set.find(c) != std::string::npos);
}

/* This complex function is meant to filter out all invalid formats.
 it does't pass scientific notation or chars denoted in any way other than 'X'. */
static bool isValidLiteral(const std::string &literal)
{
	size_t	i = 0;

	if (literal.size() == 0 || (literal.size() == 1 && !isdigit(literal.at(0))))
		return (false); // "" + -

	if (literal.size() == CHAR_LITERAL_CHAR_LENGTH && static_cast<unsigned char>(literal.at(CHAR_LITERAL_CHAR_LENGTH - 2)) > ASCII_TABLE_SIZE)
		return (false); // Character out of ascii range

	if (literal.size() == CHAR_LITERAL_CHAR_LENGTH
		&& literal.at(0) == '\''
		&& literal.at(CHAR_LITERAL_CHAR_LENGTH - 1) == '\'')
		return (true); // 'a'
	if (literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff"
		|| literal == "nan" || literal == "nanf")
		return (true); // special cases

	if (isInSet(literal.at(0), "+-"))
		i++;
	if (literal.at(i) == '.')
		return (false); //+.0 +.0f (no need for a size() check here since we've checked for "+" and "-")
	while (i < literal.size())
	{// This must be done in "C style" programming 🥰 algorithms are prohibited in this module.
		if (!isdigit(literal.at(i))) // I'm not complaining, I love C style.
		{
			if (literal.at(i) == '.')
			{
				i++;
				if (literal.size() == i)
					return (false); //1.
				while (literal.size() > i && isdigit(literal.at(i)))
					i++;
				if (literal.at(i - 1) == '.')
					return (false); // 1.f 
				if (literal.size() == i || (literal.at(i) == 'f' && literal.size() == i + 1))
					return (true); // 1.112 1.112f
				return (false);
			}
			return (false); // -1a1 -a +1a1 +a
		}
		i++;
	}
	return (true); // +111 -111 111
} // NOTE This needs refactoring, but it's unit tested and works soooo.. I'm not touching it.

/* truncateLiteral() truncates (if present) '+' from the start of the string literal
	as well as all leading zeros present in the integral. */
static std::string truncateLiteral(const std::string &literal)
{	
	size_t	start = 0;
	size_t	first_non_zero;
	bool	plus_sign_flag = false;

	if (literal == "+inf" || literal == "+inff")
		return (literal);
	if (literal.at(0) == '+' || literal.at(0) == '-')
		start++;
	if (literal.at(0) == '+')
		plus_sign_flag = true;
	first_non_zero = literal.find_first_not_of('0', start);
	if (first_non_zero == std::string::npos)
		first_non_zero = literal.size() - 1;
	if (literal.at(first_non_zero) == '.')
		first_non_zero--;
	if (plus_sign_flag == false)
		return (literal.substr(0, start) + literal.substr(first_non_zero));
	return (literal.substr(first_non_zero));
} // TODO potential for a refactor

/* returns the amount of digits that make up the integral part of a string literal.
	If present the negative sign is included */
static size_t	findIntegralSize(const std::string &literal)
{
	size_t	pos = 0;
	size_t	start = 0;

	if (literal.at(0) == '+')
		start++;
	if (literal.at(0) == '-')
		pos++;
	while (literal.size() > pos && literal[pos] != '.')
		pos++;
	return (pos - start);
}

static void printPosInf(void)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

static void printNegInf(void)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

static void printNan(void)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static bool isFarOverflow(std::string literal)
{
	size_t		integral_size = findIntegralSize(literal);
	bool		is_positive = true;

	if (literal.at(0) == '-')
		is_positive = false;
	if (((integral_size > POSITIVE_OVERFLOW_CHAR_LENGTH && is_positive == true))
		|| (integral_size > NEGATIVE_OVERFLOW_CHAR_LENGTH && is_positive == false))
		return (true);
	return (false);
}
/* checkForOverFlow() checks whether a string literal is out of its TYPE_MIN TYPE_MAX range.
	If it is, it will print the appropriate values and will return true.*/
template<typename D>
static bool checkForOverflow(const std::string &literal, const D &cast_literal)
{
	static_cast<void>(cast_literal);
	long long	overflow_checker = std::atoll(literal.c_str());
	bool		is_positive = true;
	bool		is_far_overflow = isFarOverflow(literal);

	if (literal.at(0) == '-')
		is_positive = false;
	if (std::numeric_limits<D>::is_integer)
	{
		if (is_far_overflow == true)
		{
			if (is_positive == true)
				printPosInf();
			else
				printNegInf();
		}
        else if (overflow_checker > static_cast<long long>(std::numeric_limits<D>::max()))
			printPosInf();
		else if (overflow_checker < static_cast<long long>(std::numeric_limits<D>::min()))
			printNegInf();
		else
			return (false);
    }
	else
	{ // floating-point values
        double value = std::strtod(literal.c_str(), 0);
        if (value >= std::numeric_limits<D>::max())
			printPosInf();
        else if (value <= -std::numeric_limits<D>::max())
			printNegInf();
		else
			return (false);
    }
	return (true);
}

/* resolveSpecial() looks for nan, inf, and overflows from a string literal. It will
	return true if it finds and prints a special case and false when it finds nothing. */
template<typename D>
static bool resolveSpecial(const std::string &literal, const D &cast_literal)
{
	if (literal == "nan" || literal == "nanf")
		printNan();
	else if (literal == "+inff" || literal == "+inf")
		printPosInf();
	else if (literal == "-inff" ||	literal == "-inf")
		printNegInf();
	else
		return (checkForOverflow(literal, cast_literal));
	return (true);
}

template<typename D>
static void printCharFromLiteral(const D &cast_literal)
{
	if (cast_literal > ASCII_TABLE_SIZE || cast_literal < 0)
		std::cout << "char: Impossible" << std::endl;
	else if (std::isgraph(static_cast <char> (cast_literal)) == false)
		std::cout << "char: Non-displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast <char> (cast_literal) << "\'" << std::endl;
}

template<typename D>
static void printIntFromLiteral(const std::string &literal, const D  &cast_literal)
{ // TODO maybe no need for overflow buffer
	size_t decimal_point_pos = literal.find_first_of('.');	
	long long overflow_buffer = atoll(literal.c_str());

	if (decimal_point_pos == std::string::npos)
		decimal_point_pos = literal.size();
	if ((decimal_point_pos > MAX_INT_CHAR_LENGTH && literal.at(0) != '-')
		|| (decimal_point_pos > MIN_INT_CHAR_LENGTH && literal.at(0) == '-')
		|| overflow_buffer < INT_MIN || overflow_buffer > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast <int> (cast_literal) << std::endl;
}

template<typename D>
static void printFloatFromLiteral(const D &cast_literal)
{
	if (floor(static_cast <double> (cast_literal)) == static_cast <double> (cast_literal)
		&& static_cast <float> (cast_literal) < NON_SCIENTIFIC_NOTATION_MAX
		&& static_cast <double> (cast_literal) > -NON_SCIENTIFIC_NOTATION_MAX)
		std::cout << "float: " << static_cast <float> (cast_literal) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast <float> (cast_literal) << "f" << std::endl;
}

template<typename D>
static void printDoubleFromLiteral(const D &cast_literal)
{
	if (floor(static_cast <double> (cast_literal)) == static_cast <double> (cast_literal)
		&& static_cast <double> (cast_literal) < NON_SCIENTIFIC_NOTATION_MAX
		&& static_cast <double> (cast_literal) > -NON_SCIENTIFIC_NOTATION_MAX)
		std::cout << "double: " << static_cast <double> (cast_literal) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast <double> (cast_literal) << std::endl;
}

/* resolveLiteral() expects a string literal already filtered by isValidLiteral()
Floats and doubles when within the limits of NON_SCIENTIFIC_NOTATION_MAX will
 always be formated with a decimal point and the first decimal place. */
template<typename D>
static void resolveLiteral(const std::string &literal, const D &cast_literal)
{
	if (resolveSpecial(literal, cast_literal) == false)
	{
		printCharFromLiteral(cast_literal);
		printIntFromLiteral(literal, cast_literal);
		printFloatFromLiteral(cast_literal);
		printDoubleFromLiteral(cast_literal);
	}
}

/* convert() takes in a string literal, interprets its type, casts it into that type,
	then casts it into three other types before printing all four types */
void ScalarConverter::convert(std::string literal)
{
	if (!isValidLiteral(literal))
		literal = "nan";
	types type = checkLiteralType(literal);
	literal = truncateLiteral(literal);
	try
	{
		switch (type)
		{
			case CHAR:
				resolveLiteral(literal, static_cast<char>(literal.at(CHAR_LITERAL_CHAR_LENGTH - 2)));
				break;
			case INT:
				resolveLiteral(literal, static_cast<int>(atoi(literal.c_str())));
				break;
			case FLOAT:
				resolveLiteral(literal, static_cast<float>(atof(literal.c_str())));
				break;
			case DOUBLE:
			{
				double	double_literal;
				std::stringstream ss(literal);
				ss >> double_literal;
				resolveLiteral(literal, static_cast<double>(double_literal));
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "ScalarConverter encountered an exception: " << e.what() << std::endl;
	}
}

//		## ### UNIT TESTS for findIntegralSize() ### ##

// static size_t	findIntegralSize(const std::string &literal)

// #include <vector>

// struct findIntegralSizeTestCase {
//     std::string input;
//     size_t expected;
//     findIntegralSizeTestCase(const std::string& i, size_t e) : input(i), expected(e) {}
// };

// void runTests(const std::vector<findIntegralSizeTestCase>& tests) {
//     for (std::vector<findIntegralSizeTestCase>::size_type i = 0; i < tests.size(); ++i) {
//         size_t result = findIntegralSize(tests[i].input);
//         std::cout << ((result == tests[i].expected) ? "[PASS] " : "[FAIL] ");
//         std::cout << "\"" << tests[i].input 
//                   << "\"		expected: " << tests[i].expected 
//                   << "		got: " << result << std::endl;
//     }
// }

// int	main(void)
// {
//     std::vector<findIntegralSizeTestCase> tests;

// 	tests.push_back(findIntegralSizeTestCase("1",			1));
// 	tests.push_back(findIntegralSizeTestCase("12",			2));
// 	tests.push_back(findIntegralSizeTestCase("123",			3));
// 	tests.push_back(findIntegralSizeTestCase("123.1",		3));
// 	tests.push_back(findIntegralSizeTestCase("123.12",		3));
// 	tests.push_back(findIntegralSizeTestCase("123.123",		3));
// 	tests.push_back(findIntegralSizeTestCase("+1",			1));
// 	tests.push_back(findIntegralSizeTestCase("+12",			2));
// 	tests.push_back(findIntegralSizeTestCase("+123",		3));
// 	tests.push_back(findIntegralSizeTestCase("+123.1",		3));
// 	tests.push_back(findIntegralSizeTestCase("+123.12",		3));
// 	tests.push_back(findIntegralSizeTestCase("+123.123",	3));
// 	tests.push_back(findIntegralSizeTestCase("-1",			2));
// 	tests.push_back(findIntegralSizeTestCase("-12",			3));
// 	tests.push_back(findIntegralSizeTestCase("-123",		4));
// 	tests.push_back(findIntegralSizeTestCase("-123.1",		4));
// 	tests.push_back(findIntegralSizeTestCase("-123.12",		4));
// 	tests.push_back(findIntegralSizeTestCase("-123.123",	4));
// 	tests.push_back(findIntegralSizeTestCase("12.2327153271372163862136218736782178",	2));
// 	tests.push_back(findIntegralSizeTestCase("12232163821637821637826178378216783.23",	35));
// 	tests.push_back(findIntegralSizeTestCase("12321321321321.23213213213213212321321",	14));
// 	tests.push_back(findIntegralSizeTestCase("+12.2327153271372163862136218736782178",	2));
// 	tests.push_back(findIntegralSizeTestCase("+12232163821637821637826178378216783.23",	35));
// 	tests.push_back(findIntegralSizeTestCase("+12321321321321.23213213213213212321321",	14));
// 	tests.push_back(findIntegralSizeTestCase("-12.2327153271372163862136218736782178",	3));
// 	tests.push_back(findIntegralSizeTestCase("-12232163821637821637826178378216783.23",	36));
// 	tests.push_back(findIntegralSizeTestCase("-12321321321321.23213213213213212321321",	15));
//     std::cout << "Running findIntegralSize() tests...\n";
//     runTests(tests);
// }


//		## ### UNIT TESTS for isValidLiteral() ### ##

// #include <vector>

// struct TestCase {
//     std::string input;
//     bool expected;
//     TestCase(const std::string& i, bool e) : input(i), expected(e) {}
// };

// void runTests(const std::vector<TestCase>& tests) {
//     for (std::vector<TestCase>::size_type i = 0; i < tests.size(); ++i) {
//         bool result = isValidLiteral(tests[i].input);
//         std::cout << ((result == tests[i].expected) ? "[PASS] " : "[FAIL] ");
//         std::cout << "\"" << tests[i].input 
//                   << "\"		expected: " << tests[i].expected 
//                   << "	got: " << result << std::endl;
//     }
// }

// int main() {
//     std::vector<TestCase> tests;

//     // NEGATIVE TESTS
// 	tests.push_back(TestCase("",		false));
// 	tests.push_back(TestCase("-",		false));
// 	tests.push_back(TestCase("+",		false));
// 	tests.push_back(TestCase("a",		false));
// 	tests.push_back(TestCase("'a",		false));
// 	tests.push_back(TestCase("a'",		false));
// 	tests.push_back(TestCase("''",		false));
// 	tests.push_back(TestCase("1.",		false));
// 	tests.push_back(TestCase("'aa",		false));
// 	tests.push_back(TestCase("'a'a",	false));
// 	tests.push_back(TestCase("1.af",	false));
// 	tests.push_back(TestCase("1.a",		false));
// 	tests.push_back(TestCase("123.",	false));
// 	tests.push_back(TestCase("1.1a",	false));
// 	tests.push_back(TestCase("+1a3",	false));
// 	tests.push_back(TestCase("-12a",	false));
// 	tests.push_back(TestCase("-.12a",	false));
// 	tests.push_back(TestCase("0.f",	false));

// 	// AI SUGGESTED TESTS
// 	tests.push_back(TestCase("'ab'",       false));  // too many chars
// 	tests.push_back(TestCase("''a'",       false));  // malformed
// 	tests.push_back(TestCase("'\\''",      false));  // escaped char? (if unsupported)
// 	tests.push_back(TestCase("'\\n'",      false));  // two chars after backslash if not allowed
// 	tests.push_back(TestCase("'''''",      false));  // garbage
// 	tests.push_back(TestCase("--1",        false));
// 	tests.push_back(TestCase("++1",        false));
// 	tests.push_back(TestCase("+-1",        false));
// 	tests.push_back(TestCase("1-2",        false));
// 	tests.push_back(TestCase("01a2",       false));
// 	tests.push_back(TestCase(" 123",       false)); // leading spaces
// 	tests.push_back(TestCase("123 ",       false)); // trailing spaces
// 	tests.push_back(TestCase("  123  ",    false));
// 	tests.push_back(TestCase(".123",       false));  // leading dot only
// 	tests.push_back(TestCase("123.",       false));  // trailing dot only
// 	tests.push_back(TestCase(".",          false));  // just a dot
// 	tests.push_back(TestCase("..1",        false));
// 	tests.push_back(TestCase("1..1",       false));
// 	tests.push_back(TestCase("1.1.1",      false));
// 	tests.push_back(TestCase("1.1ff",      false));  // repeated suffix
// 	tests.push_back(TestCase("1.f1",       false));
// 	tests.push_back(TestCase("f1",         false));
// 	tests.push_back(TestCase("1f.2",       false));
// 	tests.push_back(TestCase("1.1f2",      false));
// 	tests.push_back(TestCase("inf",        false));  // missing sign?
// 	tests.push_back(TestCase("-in",        false));
// 	tests.push_back(TestCase("nann",       false));
// 	tests.push_back(TestCase("nanaf",      false));
// 	tests.push_back(TestCase("nanff",      false));
// 	tests.push_back(TestCase("+inffx",     false));
// 	tests.push_back(TestCase("+infx",      false));
// 	tests.push_back(TestCase("inff",       false));  // no sign
// 	tests.push_back(TestCase("++inf",      false));
// 	tests.push_back(TestCase("--inf",      false));
// 	tests.push_back(TestCase("123f4",      false));
// 	tests.push_back(TestCase("123.45.6",   false));
// 	tests.push_back(TestCase("1e10",       false));  // if scientific notation is not supported
// 	tests.push_back(TestCase("1e-3",       false));
// 	tests.push_back(TestCase("NaN",        false));  // case sensitivity
// 	tests.push_back(TestCase("Inf",        false));
// 	tests.push_back(TestCase("nanF",       false));
// 	tests.push_back(TestCase("inff",       false));  // no sign
// 	tests.push_back(TestCase(std::string("\xF0"), false)); // char with value > 127 if signed

//     // POSITIVE TESTS
//     tests.push_back(TestCase("'a'",		true));
//     tests.push_back(TestCase("-123",	true));
//     tests.push_back(TestCase("+123",	true));
//     tests.push_back(TestCase("123",		true));
//     tests.push_back(TestCase("+inf",	true));
//     tests.push_back(TestCase("nanf",	true));
//     tests.push_back(TestCase("123.4f",	true));
//     tests.push_back(TestCase("123.4",	true));
//     tests.push_back(TestCase("123.421",	true));
//     tests.push_back(TestCase("123.42f",	true));
//     tests.push_back(TestCase("-3.42f",	true));

// 	// AI SUGGESTED TESTS
// 	tests.push_back(TestCase("'''",        true));  // missing end quote
// 	tests.push_back(TestCase("0",          true));
// 	tests.push_back(TestCase("+0",         true));
// 	tests.push_back(TestCase("-0",         true));
// 	tests.push_back(TestCase("0.0",        true));
// 	tests.push_back(TestCase("-0.0",       true));
// 	tests.push_back(TestCase("+0.0",       true));
// 	tests.push_back(TestCase("0.0f",       true));
// 	tests.push_back(TestCase("42.0",       true));
// 	tests.push_back(TestCase("42.0f",      true));
// 	tests.push_back(TestCase("003.1",     true));   // leading zeros acceptable?
// 	tests.push_back(TestCase("-inf",       true));
// 	tests.push_back(TestCase("+inff",      true));
// 	tests.push_back(TestCase("-inff",      true));
// 	tests.push_back(TestCase("nan",        true));
// 	tests.push_back(TestCase("'b'",        true));
// 	tests.push_back(TestCase("'0'",        true));
// 	tests.push_back(TestCase("' '",        true));  // space

//     std::cout << "Running tests...\n";
//     runTests(tests);

//     return 0;
// }


// INT TESTER

// #include <iostream>
// #include <sstream>
// #include <vector>
// #include <string>
// #include <climits>
// #include <cfloat>
// #include <cstdlib>
// #include <cstdio>   // <-- add this for sprintf

// void resolveInt(std::string literal); // forward declaration

// // Helper to capture std::cout output
// std::string captureResolveIntOutput(const std::string& input) {
//     std::stringstream buffer;
//     std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
//     resolveInt(input);
//     std::cout.rdbuf(oldCout);
//     return buffer.str();
// }

// struct TestCase {
//     std::string input;
//     std::string expected;
// };

// int main() {
//     std::vector<TestCase> tests;
    
//     // Regular tests
//     tests.push_back(TestCase());
//     tests.back().input = "65";
//     tests.back().expected = "char: A\nint: 65\nfloat: 65.0f\ndouble: 65.0\n";

//     tests.push_back(TestCase());
//     tests.back().input = "7";
//     tests.back().expected = "char: Non-displayable\nint: 7\nfloat: 7.0f\ndouble: 7.0\n";

//     tests.push_back(TestCase());
//     tests.back().input = "300";
//     tests.back().expected = "char: Impossible\nint: 300\nfloat: 300.0f\ndouble: 300.0\n";

//     tests.push_back(TestCase());
//     tests.back().input = "-5";
//     tests.back().expected = "char: Impossible\nint: -5\nfloat: -inff\ndouble: -inf\n";

//     // Min/Max tests
//     char buf[64];

//     // INT_MAX
//     tests.push_back(TestCase());
//     sprintf(buf, "%d", INT_MAX);
//     tests.back().input = buf;
//     sprintf(buf, "char: Impossible\nint: %d\nfloat: +inff\ndouble: +inf\n", INT_MAX);
//     tests.back().expected = buf;

//     // INT_MIN
//     tests.push_back(TestCase());
//     sprintf(buf, "%d", INT_MIN);
//     tests.back().input = buf;
//     sprintf(buf, "char: Impossible\nint: %d\nfloat: -inff\ndouble: -inf\n", INT_MIN);
//     tests.back().expected = buf;

//     // FLT_MAX (converted to int)
//     tests.push_back(TestCase());
//     sprintf(buf, "%d", (int)FLT_MAX);
//     tests.back().input = buf;
//     sprintf(buf, "char: Impossible\nint: %d\nfloat: +inff\ndouble: +inf\n", (int)FLT_MAX);
//     tests.back().expected = buf;

//     // DBL_MAX (converted to int)
//     tests.push_back(TestCase());
//     sprintf(buf, "%d", (int)DBL_MAX);
//     tests.back().input = buf;
//     sprintf(buf, "char: Impossible\nint: %d\nfloat: +inff\ndouble: +inf\n", (int)DBL_MAX);
//     tests.back().expected = buf;

//     // Loop without C++11
//     for (size_t i = 0; i < tests.size(); ++i) {
//         std::string output = captureResolveIntOutput(tests[i].input);
//         std::cout << "Input: " << tests[i].input 
//                   << "\nExpected Output:\n" << tests[i].expected
//                   << "Actual Output:\n" << output
//                   << "----------------\n";
//     }

//     return 0;
// }