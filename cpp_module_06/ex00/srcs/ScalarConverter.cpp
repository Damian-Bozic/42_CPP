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

ScalarConverter::ScalarConverter()
{
	
}

// ScalarConverter::ScalarConverter(void)
// {
// }

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	static_cast<void>(other);
}

ScalarConverter::~ScalarConverter()
{

}

int checkLiteralType(std::string literal)
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

void resolveChar(std::string literal)
{
	std::cout << "resolveChar" << std::endl;
	if (std::isgraph(static_cast <char> (literal.at(1))) == false)
		std::cout << "char: Non-displayable" << std::endl;
	else
		std::cout << "char: " << literal << std::endl;
	std::cout << "int: " << static_cast <int> (literal.at(1)) << std::endl;
	std::cout << "float: " << static_cast <float> (literal.at(1)) << ".0f" << std::endl;
	std::cout << "double: " << static_cast <double> (literal.at(1)) << ".0" << std::endl;
}

// template<typename D>
// std::string	getEvery(D literal) {
// 	if (std::numeric_limits<D>::min() < literal || std::numeric_limits<D>::max() > limits)
// 	..

// 	int test = int(literal);

// 	std::cout << std::to_string(test);

// 	float test = float(literal);

// 	std::count << test;
// }

// template<typename Type>
// class Variable {
// 	Type	value;

// 	Variable() {
// 		value = Type();
// 	}
// 	Type	Variable(const Type &other) {}

// 	Type	operator+(const Type &other) {
// 		this->value += other.value;
// 	}
// }

// Type test = new Variable<std::string>();


//  template<typename D>
// std::string	getEvery(D literal) {
// 	if (std::numeric_limits<D>::min() < literal || std::numeric_limits<D>::max() > limits)
// 	..

// 	int test = int(literal);

// 	std::cout << std::to_string(test);

// 	float test = float(literal);

// 	std::count << test;
// }

// template<typename Type>


// for the love of god unit test this TODO
void resolveInt(std::string literal)
{
	bool	limits_flag = false;
	int		literal_int = atoi(literal.c_str());

	if (literal.size() > 10 && ((atoll(literal.c_str()) > INT_MAX || atoll(literal.c_str()) < INT_MIN)))
		limits_flag = true;
	
	if (literal_int > 127 || literal_int < 0 || limits_flag == true)
		std::cout << "char: Impossible" << std::endl;
	else if (std::isgraph(static_cast <char> (literal_int)) == false)
		std::cout << "char: Non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast <char> (literal_int) << std::endl;

	if (limits_flag == true)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << literal_int << std::endl;

	if (literal_int < FLT_MIN || (limits_flag == true && literal.at(0) == '-'))
		std::cout << "float: -inff" << std::endl;
	else if (literal_int > FLT_MAX || limits_flag == true)
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: " << (static_cast <float> (literal_int)) << ".0f" << std::endl;
	
	if (literal_int < DBL_MIN || (limits_flag == true && literal.at(0) == '-'))
		std::cout << "double: -inf" << std::endl;
	else if (literal_int > DBL_MAX || limits_flag == true)
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << "double: " << static_cast <double> (literal_int) << ".0" << std::endl; // DBL_MAX
}

void resolveFloat(std::string literal)
{
	std::cout << "resolveFloat" << std::endl; //TODO remove this
	std::cout << literal << std::endl; //TODO remove this
}

void resolveDouble(std::string literal)
{
	std::cout << "resolveDouble" << std::endl; //TODO remove this
	std::cout << literal << std::endl; //TODO remove this
}

bool isInSet(char c, const std::string& set)
{
	return (set.find(c) != std::string::npos);
}

bool isValidLiteral(const std::string& literal)
{
	size_t	i = 0;

	if (literal.size() == 0 || (literal.size() == 1 && !isdigit(literal.at(0))))
		return (false); // "" + -
	if (literal.size() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'')
		return (true); // 'a'
	if (literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff"
		|| literal == "nan" || literal == "nanf")
		return (true); // special case
	if (isInSet(literal.at(0), "+-"))
		i++;
	if (literal.at(i) == '.')
		return (false); //+.0 +.0f (no need for a size() check here since we've checked for "+" and "-")
	while (i < literal.size())
	{// This must be done in "C style" programming since I'm not allowed <algorithm> in this module 🥰
		if (!isdigit(literal.at(i)))	// not that I'm complaining, I love me some C style <3
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
}

void ScalarConverter::convert(std::string literal)
{
	if (!isValidLiteral(literal))
		resolveDouble("nan");
	int	type = checkLiteralType(literal);
	std::cout << "type number: " << type << std::endl;
	switch (type)
	{
		case 1: resolveChar(literal); break;
		case 2: resolveInt(literal); break;
		case 3: resolveFloat(literal); break;
		case 4: resolveDouble(literal);
	}
}

//		## ### UNIT TESTS ### ##

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